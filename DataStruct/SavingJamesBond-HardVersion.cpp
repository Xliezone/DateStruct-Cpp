#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct point {
	int x;
	int y;
};

int BFS(vector<point>& vers, int DD, vector<int>& dist, vector<int>& path) {
	queue<int> queue;
	for (auto i = 0; i < vers.size(); i++) {
		if (pow(vers[i].x, 2) + pow(vers[i].y, 2) <= pow(DD + 15 / 2, 2)) {
			dist[i] = 1;
			path[i] = -1;
			queue.push(i);
		}
	}
	if (queue.empty()) {
		return 0;
	}
	auto min = 1000;
	auto pace = -1;
	while (!queue.empty()) {
		auto top = queue.front();
		queue.pop();
		if (50 - abs(vers[top].x) <= DD || 50 - abs(vers[top].y) <= DD) {
			if (dist[top] < min)
			{
				min = dist[top];
				pace = top;
			}
			continue;
		}
		for (auto i = 0; i < vers.size(); i++) {
			if (dist[i] == -1 && pow(vers[top].x - vers[i].x, 2) + pow(vers[top].y - vers[i].y, 2) <= DD*DD) {
				dist[i] = dist[top] + 1;
				path[i] = top;
				queue.push(i);
			}
		}
	}
	return pace;
}

void put(vector<point>& vers, vector<int>& path, int pace)
{
	if (pace > -1)
	{
	put(vers, path, path[pace]);
	cout << vers[pace].x << " " << vers[pace].y << endl;
	}
}

int main() {
	int NN, DD;
	cin >> NN >> DD;
	vector<point> vers;
	for (auto i = 0; i < NN; i++) {
		point p;
		cin >> p.x >> p.y;
		vers.push_back(p);
	}
	vector<int> dist(NN, -1);
	vector<int> path(NN, -1);
	int pace = BFS(vers, DD, dist, path);
	if (pace > 0) {
		cout << dist[pace] + 1 << endl;
		put(vers, path, pace);
	}
	else {
		cout << 0 << endl;
	}
}