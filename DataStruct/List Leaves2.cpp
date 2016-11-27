#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int data;
	int left;
	int right;
};

int read(vector<Node> &y)
{
	int n;
	cin >> n;
	int sum = (n - 1) * n / 2;
	int d = 0;
	while (n-- != 0)
	{
		char tempL, tempR;
		cin >> tempL >> tempR;
		int l = tempL != '-' ? tempL - '0' : 0;
		int r = tempR != '-' ? tempR - '0' : 0;
		sum = sum - l - r;
		Node temp;
		temp.data = d;
		temp.left = tempL != '-' ? tempL - '0' : -1;
		temp.right = tempR != '-' ? tempR - '0' : -1;
		y.push_back(temp);
		d++;
	}
	return sum;
}

int main(int argc, char* argv[])
{
	vector<Node> T;
	int head = read(T);
	vector<int> v;
	queue<Node> que;
	que.push(T[head]);
	while (!que.empty())
	{
		Node temp = que.front();
		que.pop();
		if (temp.left == -1 && temp.right == -1)
		{
			v.push_back(temp.data);
		}
		if (temp.left != -1)
		{
			que.push(T[temp.left]);
		}
		if (temp.right != -1)
		{
			que.push(T[temp.right]);
		}
	}
	for (auto i = 0; i < v.size() - 1; i++)
	{
		cout << v[i] << " ";
	}
	cout << v[v.size() - 1] << endl;
	return 0;
}
