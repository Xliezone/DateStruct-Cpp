#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

struct point
{
	int x;
	int y;
};

bool BFS(vector<point>& vers, vector<bool>& visited, int DD)
{
	queue<point> queue;
	for (auto i = 0; i < vers.size(); i++)
	{
		if (pow(vers[i].x, 2) + pow(vers[i].y, 2) <= pow(DD + 15 / 2, 2))
		{
			visited[i] = true;
			queue.push(vers[i]);
		}
	}
	if (queue.empty())
	{
		return false;
	}
	while (!queue.empty())
	{
		auto top = queue.front();
		queue.pop();
		if (50 - abs(top.x) <= DD || 50 - abs(top.y) <= DD)
		{
			return true;
		}
		for (auto i = 0; i < vers.size(); i++)
		{
			if (!visited[i] && pow(top.x - vers[i].x, 2) + pow(top.y - vers[i].y, 2) <= DD*DD)
			{
				visited[i] = true;
				queue.push(vers[i]);
			}
		}
	}
	return false;
}

int main()
{
	int NN, DD;
	cin >> NN >> DD;
	vector<point> vers;
	for (auto i = 0; i < NN; i++)
	{
		point p;
		cin >> p.x >> p.y;
		vers.push_back(p);
	}
	vector<bool> visited(NN, false);
	if (BFS(vers, visited, DD))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}