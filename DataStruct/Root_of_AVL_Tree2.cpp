#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct Node
{
	int data;
	Node* left = nullptr;
	Node* right = nullptr;
	int height = 0;
}* Tree;

int _max(int a, int b)
{
	return a > b ? a : b;
}

int getHeight(Tree& T)
{
	return T ? T->height : 0;
}

void LL(Tree& T)
{
	auto p = T;
	auto q = T->left;
	p->left = q->right;
	q->right = p;
	p->height = _max(getHeight(p->left), getHeight(p->right)) + 1;
	q->height = _max(getHeight(q->left), getHeight(q->right)) + 1;
	T = q;
}

void RR(Tree& T)
{
	auto p = T;
	auto q = T->right;
	p->right = q->left;
	q->left = p;
	p->height = _max(getHeight(p->left), getHeight(p->right)) + 1;
	q->height = _max(getHeight(q->left), getHeight(q->right)) + 1;
	T = q;
}

void LR(Tree& T)
{
	RR(T->left);
	LL(T);
}

void RL(Tree& T)
{
	LL(T->right);
	RR(T);
}

void insert(Tree& T, int num)
{
	if (!T)
	{
		Tree temp = new Node;
		temp->data = num;
		T = temp;
	}
	else
	{
		if (num < T->data)
		{
			insert(T->left, num);
			if (abs(getHeight(T->left) - getHeight(T->right)) == 2)
			{
				if (num < T->left->data)
				{
					LL(T);
				}
				else
				{
					LR(T);
				}
			}
		}
		else
		{
			 insert(T->right, num);
			if (abs(getHeight(T->left) - getHeight(T->right)) == 2)
			{
				if (num > T->right->data)
				{
					RR(T);
				}
				else
				{
					RL(T);
				}
			}
		}
	}
	T->height = _max(getHeight(T->left), getHeight(T->right)) + 1;
}

int main()
{
	int n;
	cin >> n;
	Tree T = nullptr;
	while (n-- != 0)
	{
		int data;
		cin >> data;
		insert(T, data);
	}
	cout << T->data << endl;
	return 0;
}
