#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define INF 10000

using namespace std;

struct graph
{
	int vertex;
	int edge;
	vector<vector<int>> matrix;
};

graph init(int v, int e)
{
	graph g;
	g.vertex = v;
	g.edge = e;
	g.matrix = vector<vector<int>>(v, vector<int>(v, -1));
	return g;
}

void insert(graph& g, int v1, int v2, int weight)
{
	g.matrix[v1][v2] = weight;
}

int topSort(graph& g, vector<int>& order, stack<vector<int>>& key)
{
	vector<int> indegree(g.vertex, 0);

	for (auto i = 0; i < g.vertex; i++)
	{
		for (auto j = 0; j < g.vertex; j++)
		{
			if (g.matrix[i][j] != -1)
			{
				indegree[j]++;
			}
		}
	}

	queue<int> queue;
	vector<int> max(g.vertex, 0);
	for (auto i = 0; i < indegree.size(); i++)
	{
		if (indegree[i] == 0)
		{
			queue.push(i);
		}
	}

	int count = 0;

	while (!queue.empty())
	{
		auto v = queue.front();
		queue.pop();
		order[count++] = v;

		for (auto i = 0; i < g.vertex; i++)
		{
			if (g.matrix[v][i] != -1)
			{
				indegree[i]--;
				if (max[v] + g.matrix[v][i] > max[i])
				{
					max[i] = max[v] + g.matrix[v][i];
				}
				if (indegree[i] == 0)
				{
					queue.push(i);
				}
			}
		}
	}

	if (count != g.vertex)
	{
		return -1;
	}

	auto it = order.back();
	vector<int> last(g.vertex, max[it]);
	last[it] = max[it];
	vector<bool> visit(g.vertex, false);
	queue.push(it);
	visit[it] = true;

	while (!queue.empty())
	{
		for (auto w = g.vertex - 1; w >= 0; w--)
		{
			if (g.matrix[w][queue.front()] != -1)
			{
				if (last[w] > last[queue.front()] - g.matrix[w][queue.front()])
				{
					last[w] = last[queue.front()] - g.matrix[w][queue.front()];
				}
				if (!visit[w]) {
					queue.push(w);
					visit[w] = true;
				}
				if (last[queue.front()] - g.matrix[w][queue.front()] == max[w])
				{
					key.push({w, queue.front()});
				}
			}
		}
		queue.pop();
	}


	return max[order.back()];
}

int main()
{
	int N, M;
	cin >> N >> M;
	auto g = init(N, M);
	for (auto i = 0; i < M; i++)
	{
		int v1, v2, weight;
		cin >> v1 >> v2 >> weight;
		insert(g, v1 - 1, v2 - 1, weight);
	}

	vector<int> order(N);
	stack<vector<int>> key;
	auto sum = topSort(g, order, key);
	if (sum == -1)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	cout << sum << endl;

	while (!key.empty())
	{
		cout << key.top()[0] + 1 << "->" << key.top()[1] + 1 << endl;
		key.pop();
	}
}
