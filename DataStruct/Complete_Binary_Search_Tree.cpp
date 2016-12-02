#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void in_order(int i, int size, vector<int>& order)
{
	if (i*2 <= size)
	{
		in_order(i * 2, size, order);
	}
	order.push_back(i);
	if (i*2 +1 <= size)
	{
		in_order(i * 2 + 1, size, order);
	}
}

int main()
{
	int n;
	cin >> n;
	auto size = n;
	vector<int> T(n+1, -1);
	vector<int> temp;
	while (n-- != 0)
	{
		int m;
		cin >> m;
		temp.push_back(m);
	}
	sort(temp.begin(), temp.end());
	vector<int>  order;
	in_order(1, size, order);
	for (auto i = 0; i < size; i++)
	{
		T[order[i]] = temp[i];
	}
	for (auto i = 1; i < T.size() -1; i++)
	{
		cout << T[i] << " ";
	}
	cout << T.back() << endl;
}

/*A Binary Search Tree(BST) is recursively defined as a binary tree which has the following properties :

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
A Complete Binary Tree(CBT) is a tree that is completely filled, with the possible exception of the bottom level, which is filled from left to right.

Now given a sequence of distinct non - negative integer keys, a unique BST can be constructed if it is required that the tree must also be a CBT.You are supposed to output the level order traversal sequence of this BST.

Input Specification :

Each input file contains one test case.For each case, the first line contains a positive integer NN(\le 1000≤1000).Then NN distinct non - negative integer keys are given in the next line.All the numbers in a line are separated by a space and are no greater than 2000.

Output Specification :

For each test case, print in one line the level order traversal sequence of the corresponding complete binary search tree.All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input :

10
1 2 3 4 5 6 7 8 9 0
Sample Output :

6 3 8 1 5 7 9 0 2 4

思路：
在完全二叉树中，根节点为i，则左子节点为2i，右节点为2i+1；叶节点个数为2^(i-1),所有节点个数最多为2^i-1；
二叉搜索树中，中序遍历正好为递增序列，前提条件是数据为有序不重复；
*/