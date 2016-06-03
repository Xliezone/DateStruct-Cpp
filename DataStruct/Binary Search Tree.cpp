#include <iostream>
#include <vector>

using namespace std;

typedef struct Node
{
	int val;
	Node* left, *right;
	bool flag;
}* Tree;

void Insert(int num, Tree &tree) {
	if (tree == 0) {
		Tree node = (Tree) new Tree;
		node->val = num;
		node->left = 0;
		node->right = 0;
		node->flag = false;
		tree = node;
//		delete node;
	}
	if (num < tree->val) {
		Insert(num, tree->left);
	}
	if (num > tree->val) {
		Insert(num, tree->right);
	}
}

bool Compare(int num, Tree &tree) {
	if (tree->flag == false) {
		if (num == tree->val) {
			tree->flag = true;
			return true;
		}
		else
			return false;
	}
	else {
		if (num < tree->val)
			return Compare(num, tree->left);
		if (num > tree->val)
			return Compare(num, tree->right);
	}
}

void Reset(Tree &tree) {
	tree->flag = false;
	if (tree->left != 0)
		Reset(tree->left);
	if (tree->right != 0)
		Reset(tree->right);
}

vector<string> answer;

void ReadA(int N, int L) {
	int array[L + 1][N];
	for (int i = 0; i < L + 1; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> array[i][j];
		}
	}
	//sample tree
	Tree SampleTree = 0;
	for (int i = 0; i < N; ++i)
	{
		Insert(array[0][i], SampleTree);
	}
	//trees to compare
	for (int j = 1; j < L + 1; j++) {
		bool count = true;
		for (int i = 0; i < N; ++i)
		{
			if (Compare(array[j][i], SampleTree))
				continue;
			else {
				count = false;
				answer.push_back("No");
				break;
			}
		}
		if (count)
			answer.push_back("Yes");
		Reset(SampleTree);
	}
}

void Read() {
	int N;
	cin >> N;
	if (N != 0) {
		int L;
		cin >> L;
		ReadA(N, L);
		Read();
	}
}

void Print(vector<string> &answer) {
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
}

int main() {
	Read();
	Print(answer);
	return 0;
}
