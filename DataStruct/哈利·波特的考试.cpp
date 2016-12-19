#include <iostream>
#include <vector>
#define Max 1000

using namespace std;



struct Edge
{
	int v1, v2;
	int weight;
};

typedef struct Graph
{
	int vertex;
	int edge;
	vector<vector<int>> G;
}* graph;

graph init(int v, int e)
{
	graph g = new Graph;
	g->vertex = v;
	g->edge = e;
	g->G = vector<vector<int>>(v, vector<int>(v, Max));
	return g;
}

void insertEdge(graph& g, Edge e)
{
	g->G[e.v1-1][e.v2-1] = e.weight;
	g->G[e.v2-1][e.v1-1] = e.weight;
}

void floyd(graph& g, vector<vector<int>>& d, vector<vector<int>>& path)
{
	int k, i, j;
	for (i = 0; i < g->vertex; i++)
	{
		for (j = 0; j < g->vertex; j++)
		{
			d[i][j] = g->G[i][j];
			path[i][j] = -1;
		}
	}
	
	for (k = 0; k < g->vertex; k++)
	{
		for (i = 0; i < g->vertex; i++)
		{
			for (j = 0; j < g->vertex; j++)
			{
				if (d[i][k] + d[k][j] < d[i][j] && i != j)
				{
					d[i][j] = d[i][k] + d[k][j];
					path[i][j] = k;
				}
			}
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	auto g = init(N, M);
	for (auto i = 0; i < M; i++)
	{
		Edge e;
		cin >> e.v1 >> e.v2 >> e.weight;
		insertEdge(g, e);
	}

	vector<vector<int>> D(N, vector<int>(N));
	vector<vector<int>> path(N, vector<int>(N));
	floyd(g, D, path);

	for (auto i = 0; i < N; i++)
	{
		for (auto j = 0; j < N; j++)
		{
			if (D[i][j] == Max && i != j)
			{
				cout << 0 << endl;
				return 0;
			}
		}
	}
	
	auto min = Max;
	auto num = 0;
	auto len = 0;
	for (auto i = 0; i < N; i++)
	{
		auto cox = 0;
		for (auto j = 0; j < N; j++)
		{
			if (i != j && D[i][j] > cox)
			{
				cox = D[i][j];
			}
		}
		if (cox < min)
		{
			min = cox;
			num = i;
			len = cox;
		}
	}
	cout << num + 1 << " " << len << endl;
}