#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef struct Node
{
	int data;
	Node* left = nullptr;
	Node* right = nullptr;
	bool visited = false;
}* Tree;

void read(int length, vector<int>& real, vector<vector<int>>& sam)
{
	int sample;
	cin >> sample;
	for (auto i = 0; i < length; i++)
	{
		int n;
		cin >> n;
		real.push_back(n);
	}
	while (sample-- != 0)
	{
		vector<int> temp;
		for (auto i = 0; i < length; i++)
		{
			int n;
			cin >> n;
			temp.push_back(n);
		}
		sam.push_back(temp);
	}
}

void build(Tree& T, int num)
{
	if (!T)
	{
		Tree temp = new Node;
		temp->data = num;
		T = temp;
	}
	else
	{
		if (num > T->data)
		{
			build(T->right, num);
		}
		else
		{
			build(T->left, num);
		}
	}
}

bool visit(Tree& T, int sam)
{
	if (T->visited)
	{
		if (sam == T->data)
			return false;
		if (sam < T->data)
		{
			return visit(T->left, sam);
		}
		if (sam > T->data)
		{
			return visit(T->right, sam);
		}
	}
	else
	{
		if (sam != T->data)
		{
			return false;
		}
		T->visited = true;
	}
	return true;
}

bool judge(vector<int>& real, vector<int>& sample)
{
	//build tree
	Tree Head = nullptr;
	for (auto i : real)
	{
		build(Head, i);
	}
	//	travel
	for (auto i : sample)
	{
		if (!visit(Head, i))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	vector<string> answer;
	while (true)
	{
		int length;
		cin >> length;
		if (length)
		{
			vector<int> real;
			vector<vector<int>> sample;
			read(length, real, sample);
			for (auto i : sample)
			{
				if (judge(real, i))
				{
					answer.push_back("Yes");
				}
				else
				{
					answer.push_back("No");
				}
			}
		}
		else
		{
			break;
		}
	}
	for (auto i : answer)
		cout << i << endl;
	return 0;
}
