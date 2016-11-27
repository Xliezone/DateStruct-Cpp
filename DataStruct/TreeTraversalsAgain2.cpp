#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

using Array = vector<int>;

void solve(Array& pre_vector, Array& in_vector, Array& post_vector, int pre_index, int in_index, int post_index, int length);

int main()
{
	int n;
	cin >> n;
	n *= 2;
	stack<int> tree;
	vector<int> pre, in;
	while (n-- != 0)
	{
		string com;
		int data;
		cin >> com;
		if (com == "Push")
		{
			cin >> data;
			tree.push(data);
			pre.push_back(data);
		}
		else if (com == "Pop")
		{
			in.push_back(tree.top());
			tree.pop();
		}
	}
	Array post(pre.size());
	solve(pre, in, post, 0, 0, 0, pre.size());
	for (auto i = 0; i < post.size() - 1; i++)
	{
		cout << post[i] << " ";
	}
	cout << post.back() << endl;
}

void solve(int* pre, int* in, int* post, int preL, int inL, int postL, int n)
{
	int root;
	if (0 == n) return;
	if (1 == n)
	{
		post[postL] = pre[preL];
		return;
	}
	root = pre[preL];
	post[postL + n - 1] = root;
	int i;
	for (i = 0; i < n; i++) if (in[inL + i] == root) break;
	solve(pre, in, post, preL + 1, inL, postL, i);
	solve(pre, in, post, preL + i + 1, inL + i + 1, postL + i, n - i - 1);
}

//分治法
/*
 * 已知中序和前序的数组								
 */
void solve(Array& pre_vector, Array& in_vector, Array& post_vector, int pre_index, int in_index, int post_index, int length)
{
//	数组长度为0，即空树
	if (length == 0)
		return;
//	长度为1，即单节点子树
	if (length == 1)
	{
		post_vector[post_index] = pre_vector[pre_index];
	}
//	长度为1以上，找到该树根节点
	int root = pre_vector[pre_index];
//	后序数组该段最后的节点必然为该树的根节点
	post_vector[post_index + length - 1] = root;
//	找到中序数组中根节点的位置
	int index;
	for (index = 0; index < length; index++)
		if (in_vector[in_index + index] == root)
			break;
//	递归根节点左边（左子树）右边（右子树）
	solve(pre_vector, in_vector, post_vector, pre_index + 1, in_index, post_index, index);
	solve(pre_vector, in_vector, post_vector, pre_index + index + 1, in_index + index + 1, post_index + index, length - index - 1);
}
