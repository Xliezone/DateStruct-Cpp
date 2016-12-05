#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Set;

int find(Set& s, int x)
{
	if (s[x] < 0)
	{
		return x;
	}
	else
	{
		return s[x] = find(s, s[x]);
	}
}

void and(Set& s, int x, int y)
{
	auto root1 = find(s, x);
	auto root2 = find(s, y);
	if (s[root1] > s[root2])
	{
		s[root2] += s[root1];
		s[root1] = root2;
	}
	else
	{
		s[root1] += s[root2];
		s[root2] = root1;
	}
}

void input(Set& s, int x, int y)
{
	and (s, x, y);
}

void check(Set& s, int x, int y)
{
	auto root1 = find(s, x);
	auto root2 = find(s, y);
	if (root1 == root2)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}

void conclution(Set& s)
{
	int count = -1;
	for (auto i : s)
	{
		if (i < 0)
		{
			count++;
		}
	}
	if (count == 1)
	{
		cout << "The network is connected." << endl;
	}
	else
	{
		cout << "There are " << count << " components." << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	Set s(n+1, -1);
	char op;
	do
	{
		cin >> op;
		int x, y;
		switch (op)
		{
		case 'I':
			cin >> x >> y;
			input(s, x, y);
			break;
		case 'C':
			cin >> x >> y;
			check(s, x, y);
			break;
		case 'S':
			conclution(s);
		}
	}
	while (op != 'S');
	return 0;
}
