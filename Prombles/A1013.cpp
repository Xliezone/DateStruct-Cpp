/*
 * A1013.cpp
 *
 *  Created on: May 24, 2017
 *      Author: xliez
 */

#include <iostream>
#include <algorithm>

int graph[1000][1000];
bool visit[1000];

void dfs(int i) {
	visit[i] = true;
	for (int j = 0; j < 1000; j++) {
		if (visit[j] == false && graph[i][j] == 1) {
			dfs(j);
		}
	}
}

int main() {
	int N, M, K;
	std::cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int a, b;
		std::cin >> a >> b;
		graph[a][b] = graph[b][a] = 1;
	}
	for (int i = 0; i < K; i++) {
		std::fill(visit, visit + 1000, false);
		int n;
		std::cin >> n;
		visit[n] = true;
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (visit[j] == false) {
				dfs(j);
				cnt++;
			}
		}
		std::cout << cnt - 1 << std::endl;
	}
}

