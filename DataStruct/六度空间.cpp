#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

typedef struct graph
{
	int vertex;
	int edge;
	vector<vector<int>> g;
}* Graph;

auto create(int ver, int edge)->Graph{
	auto G = new graph;
	G->vertex = ver;
	G->edge = edge;
	G->g = vector<vector<int>>(ver+1, vector<int>(ver + 1, 0));
	return G;
}

struct deg
{
	int v;
	int degree;
};

int main()
{
	int N, M;
	cin >> N >> M;
	auto graph = create(N, M);
	for (auto i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph->g[a][b] = 1;
		graph->g[b][a] = 1;
	}
	for (auto i = 1; i <= N; i++)
	{
		vector<bool> visited(N+1, false);
		queue<deg> queue;
		visited[i] = true;
		deg temp;
		temp.v = i;
		temp.degree = 0;
		queue.push(temp);
		int fre_count = 1;
		while (!queue.empty())
		{
			auto top = queue.front();
			queue.pop();
			for (auto j = 1; j <= N; j++)
			{
				if (!visited[j] && graph->g[top.v][j] == 1 && top.degree < 6)
				{
					visited[j] = true;
					fre_count++;
					deg tp;
					tp.v = j;
					tp.degree = top.degree + 1;
					queue.push(tp);
				}
			}

		}
		cout << i << ": " << fixed << setprecision(2) << fre_count*100.00 / N  << "%" << endl;
	}
}
