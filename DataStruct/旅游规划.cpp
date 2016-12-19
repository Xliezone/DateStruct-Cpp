#include <iostream>
#include <vector>
#define INF 10000

using namespace std;

struct Edge
{
	int v1, v2;
	int length;
	int cost;
};

typedef struct Graph
{
	int vertex;
	int edge;
	vector<vector<int>> len;
	vector<vector<int>> cos;
}* graph;

graph init(int v, int e)
{
	auto g = new Graph;
	g->vertex = v;
	g->edge = e;
	g->len = vector<vector<int>>(v, vector<int>(v, INF));
	g->cos = vector<vector<int>>(v, vector<int>(v, INF));
	return g;
}

void insertEdge(graph& g, Edge e)
{
	g->len[e.v1][e.v2] = e.length;
	g->len[e.v2][e.v1] = e.length;
	g->cos[e.v1][e.v2] = e.cost;
	g->cos[e.v2][e.v1] = e.cost;
}

int findMin(graph& g, vector<int>& dist, vector<bool>& collected)
{
	auto min = INF;
	int V = -1;
	for (auto i = 0; i <g->vertex; i++)
	{
		if (!collected[i] && dist[i] < min)
		{
			min = dist[i];
			V = i;
		}
	}

	if (min < INF)
	{
		return V;
	}
	return -1;
}

void Dijkstra(graph& g,vector<int>& path, vector<int>& dist, vector<int>& cost, int SS)
{
	vector<bool> collected(g->vertex, false);
	//init dist, path
	for (auto i = 0; i < g->vertex; i++)
	{
		dist[i] = g->len[SS][i];
		cost[i] = g->cos[SS][i];
		if (dist[i] < INF)
		{
			path[i] = SS;
		}
	}

	dist[SS] = 0;
	collected[SS] = true;

	//loop start
	while (true)
	{
		auto V = findMin(g, dist, collected);
		if (V == -1)
		{
			break;
		}
		collected[V] = true;
		for (auto W = 0; W < g->vertex; W++)
		{
			if (!collected[W] && dist[V] + g->len[V][W] <= dist[W])
			{
				if (dist[V] + g->len[V][W] < dist[W] || cost[V] + g->cos[V][W] < cost[W])
				{
					dist[W] = dist[V] + g->len[V][W];
					path[W] = V;
					cost[W] = cost[V] + g->cos[V][W];
				}
			}
		}
	}
}

int main()
{
	int NN, MM, SS, DD;
	cin >> NN >> MM >> SS >> DD;
	auto g = init(NN, MM);
	for (auto i = 0; i < MM; i++)
	{
		Edge e;
		cin >> e.v1 >> e.v2 >> e.length >> e.cost;
		insertEdge(g, e);
	}

	vector<int> dist(NN, INF);
	vector<int> cost(NN, INF);
	vector<int> path(NN, -1);

	Dijkstra(g, path, dist, cost, SS);

	cout << dist[DD] << " " << cost[DD] << endl;
}