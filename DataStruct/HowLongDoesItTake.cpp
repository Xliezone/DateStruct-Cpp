#include <iostream>
#include <vector>
#include <queue>
#define INF 10000

using namespace std;

typedef vector<int> shuzu;

struct graph
{
	int vertex;
	int edge;
	vector<shuzu> matrix;
};

graph init(int v, int e)
{
	graph g;
	g.vertex = v;
	g.edge = e;
	g.matrix = vector<shuzu>(v, shuzu(v, -1));
	return g;
}

void insert(graph& g, int v1, int v2, int weight)
{
	g.matrix[v1][v2] = weight;
}

int topSort(graph& g, shuzu& order)
{
	shuzu indegree(g.vertex, 0);

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
	shuzu max(g.vertex, 0);
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
				if (indegree[i] == 0) {
					queue.push(i);
				}
			}
			
		}
	}

	if (count != g.vertex)
	{
		return -1;
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
		insert(g, v1, v2, weight);
	}

	shuzu order(N);
	auto sum = topSort(g, order);
	if (sum == -1)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	cout << sum << endl;
}