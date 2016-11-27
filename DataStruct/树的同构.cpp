#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	char data;
	char left;
	char right;
	char father = 0;
};



void read(vector<Node> &y)
{
	int n;
	cin >> n;
	while (n-- != 0)
	{
		Node temp;
		cin >> temp.data >> temp.left >> temp.right;
		y.push_back(temp);
	}
	for (auto i = 0; i < y.size(); i++)
	{
		if (y[i].left != '-')
		{
			int x = y[i].left - '0';
			y[x].father = y[i].data;
		}
		if (y[i].right != '-')
		{
			int x = y[i].right - '0';
			y[x].father = y[i].data;
		}
	}
}

bool judge(vector<Node> &y1, vector<Node> &y2)
{
	if (y1.size() != y2.size())
	{
		return false;
	}
	auto count = 0;
	for (auto &i : y1)
	{
		for (auto &j : y2)
		{
			if (i.data == j.data)
			{
				count++;
				if (i.father != j.father)
				{
					return false;
				}
			}
		}
	}
	if (count != y1.size())
	{
		return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	vector<Node> T1, T2;
	read(T1);
	read(T2);
	if (judge(T1,T2))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}
