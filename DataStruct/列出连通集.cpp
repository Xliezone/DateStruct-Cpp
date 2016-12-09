#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef int vertex;

struct edge
{
	vertex v1, v2;
	//	int weight;
};


typedef struct graph
{
	int num_v;
	int num_e;
	int G[100][100];
}* MGraph;


MGraph create(int ver_num)
{
	vertex v, w;
	MGraph graph;

	graph = new ::graph;
	graph->num_v = ver_num;
	graph->num_e = 0;
	for (v = 0; v < graph->num_v; v++)
	{
		for (w = 0; w < graph->num_v; w++)
		{
			graph->G[v][w] = 0;
		}
	}
	return graph;
}

void insertEdge(MGraph& graph, edge& e)
{
	if (graph->G[e.v1][e.v2] == 0)
	{
		graph->G[e.v1][e.v2] = 1;
		graph->G[e.v2][e.v1] = 1;
		//		graph->num_e++;
	}
}


void DFS(MGraph& graph, vertex v, vector<bool>& visited, int count)
{
	if (!visited[v])
	{
		visited[v] = true;
		if (count == 0)
		{
			cout << "{ ";
		}
		cout << v << " ";
		for (auto i = 0; i < graph->num_v; i++)
		{
			if (graph->G[v][i] == 1 && !visited[i])
			{
				DFS(graph, i, visited, count + 1);
			}
		}
		if (count == 0)
		{
			cout << "}" << endl;
		}
	}
}

void BFS(MGraph& graph, vertex v, vector<bool>& visited)
{
	if (!visited[v])
	{
		queue<vertex> queue;
		visited[v] = true;
		queue.push(v);
		cout << "{ ";

		while (!queue.empty())
		{
			auto top = queue.front();
			queue.pop();
			cout << top << " ";
			for (auto i = 0; i < graph->num_v; i++)
			{
				if (graph->G[top][i]== 1 && !visited[i])
				{
					visited[i] = true;
					queue.push(i);
				}
			}
		}
		cout << "}" << endl;
	}
}

int main()
{
	int nn, ee;
	cin >> nn >> ee;
	auto graph = create(nn);
	graph->num_e = ee;
	for (auto i = 0; i < ee; i++)
	{
		edge e;
		cin >> e.v1 >> e.v2;
		insertEdge(graph, e);
	}
	vector<bool> visited(nn, false);
	auto visited2 = visited;
	for (auto i = 0; i < nn; i++)  
	{
		DFS(graph, i, visited, 0);
	}
	for (auto i = 0; i < nn; i++)
	{
		BFS(graph, i, visited2);
	}
}
