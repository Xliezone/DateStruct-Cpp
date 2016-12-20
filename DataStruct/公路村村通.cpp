#include <iostream>
#include <vector>
#define INF 10000

using namespace std;

typedef vector<int> shuzu;

typedef struct tu
{
	int vertex;
	int edge;
	vector<shuzu> matrix;
}* graph;

graph init(int v, int e)
{
	graph g = new tu;
	g->vertex = v;
	g->edge = e;
	g->matrix = vector<shuzu>(v, shuzu(v, INF));
	return g;
}

void insert(graph& g, int v1, int v2, int len)
{
	g->matrix[v1][v2] = len;
	g->matrix[v2][v1] = len;
}

int findMin(shuzu& dist)
{
	int min = INF;
	int num = -1;

	for (auto i = 0; i < dist.size(); i++)
	{
		if (dist[i] != 0 && dist[i] < min)
		{
			min = dist[i];
			num = i;
		}
	}

	return num;
}

int prim(graph& g, graph& mst)
{
	shuzu dist(g->vertex, INF);
	shuzu parent(g->vertex, 0);
	int s = 0;

	for (auto i = 0; i < g->vertex; i++)
	{
		dist[i] = g->matrix[s][i];
	}

	dist[s] = 0;
	parent[s] = -1;
	int sumLen = 0;
	int vCount = 1;

	while (true)
	{
		int v = findMin(dist);

		if (v == -1)
		{
			break;
		}

		sumLen += dist[v];
		vCount++;
		insert(mst, parent[v], v, dist[v]);

		dist[v] = 0;
		for (auto i = 0; i < g->vertex; i++)
		{
			if (dist[i] != 0 && g->matrix[v][i] < INF)
			{
				dist[i] = g->matrix[v][i];
				parent[i] = v;
			}
		}
	}

	if (vCount != g->vertex)
	{
		return -1;
	}

	return sumLen;
}

int main()
{
	int N, M;
	cin >> N >> M;
	auto g = init(N, M);
	for (auto i = 0; i < M; i++)
	{
		int v1, v2, len;
		cin >> v1 >> v2 >> len;
		insert(g, v1 - 1, v2 - 1, len);
	}

	auto mst = init(N, N - 1);
	auto sum = prim(g, mst);

	cout << sum << endl;
}