#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node
{
	char ch = NULL;
	int fre = 0;
	node* left = nullptr;
	node* right = nullptr;
}* TreeNode;

typedef struct heap
{
	int size = 0;
	vector<TreeNode> element;
}* MinHeap;

typedef struct code_node
{
	bool flag = false;
	code_node* left = nullptr;
	code_node* right = nullptr;
}* code_tree;


void init_heap(MinHeap& h)
{
	TreeNode temp = new node;
	h->element.push_back(temp);
}

void insert(MinHeap& h, TreeNode& tn)
{
	h->element.push_back(tn);
	h->size++;
	auto i = h->size;
	auto data = h->element[i];
	while (data->fre < h->element[i / 2]->fre)
	{
		h->element[i] = h->element[i / 2];
		i /= 2;
	}
	h->element[i] = data;
}

TreeNode delet(MinHeap& h)
{
	if (h->size == 0)
	{
		return nullptr;
	}
	auto top = h->element[1];
	auto last = h->element[h->size];
	h->element.pop_back();
	h->size--;
	auto parent = 1;
	while (parent * 2 <= h->size)
	{
		auto child = parent * 2;
		if (child < h->size && h->element[child]->fre > h->element[child + 1]->fre)
		{
			child++;
		}
		if (last->fre <= h->element[child]->fre)
		{
			break;
		}
		else
		{
			h->element[parent] = h->element[child];
			parent = child;
		}
	}
	if (h->size > 0)
	{
		h->element[parent] = last;
	}
	return top;
}


TreeNode build(MinHeap& h)
{
	auto i = h->size;
	for (; i > 1; i--)
	{
		TreeNode temp = new node;
		temp->left = delet(h);
		temp->right = delet(h);
		temp->fre = temp->left->fre + temp->right->fre;
		insert(h, temp);
	}
	return delet(h);
}

int code_len(TreeNode& huffman, int depth)
{
	if (!huffman->left && !huffman->right)
	{
		return huffman->fre * depth;
	}
	return code_len(huffman->left, depth + 1) + code_len(huffman->right, depth + 1);
}

bool judge(const string& str, code_tree& ct)
{
	auto temp = ct;
	for (auto i = 0; i < str.size(); i++)
	{
		if (str[i] == '0')
		{
			if (!temp->left)
			{
				temp->left = new code_node;
				if (i == str.size() - 1) {
					temp->left->flag = true;
				}
			}
			else
			{
				if (temp->left->flag)
				{
					return false;
				}
				if (i == str.size()-1)
				{
					temp->left->flag = true;
					if (temp->left->left || temp->left->right)
					{
						return false;
					}
				}
			}
			temp = temp->left;
		}
		else
		{
			if (!temp->right)
			{
				temp->right = new code_node;
				if (i == str.size() -1) {
					temp->right->flag = true;
				}
			}
			else
			{
				if (temp->right->flag)
				{
					return false;
				}
				if (i == str.size()-1)
				{
					temp->right->flag = true;
					if (temp->right->left || temp->right->right) {
						return false;
					}
				}
			}
			temp = temp->right;
		}
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	MinHeap mh = new heap;
	init_heap(mh);
	char c;
	int fre;
	vector<int> freq;
	for (auto i = 0; i < n; i++)
	{
		cin >> c >> fre;
		freq.push_back(fre);
		TreeNode tn_node = new node;
		tn_node->ch = c;
		tn_node->fre = fre;
		insert(mh, tn_node);
	}
	auto huffmanTree = build(mh);
	auto len = code_len(huffmanTree, 0);
	int student;
	cin >> student;
	string code;

	while (student-- != 0)
	{
		int stu_len = 0;
		code_tree ct = new code_node;
		bool flag = true;
		for (auto i = 0; i < n; i++)
		{
			cin >> c >> code;
			stu_len += code.size()*freq[i];
			if (!judge(code, ct))
			{
				flag = false;
			}
		}
		if (stu_len != len || !flag)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
}
