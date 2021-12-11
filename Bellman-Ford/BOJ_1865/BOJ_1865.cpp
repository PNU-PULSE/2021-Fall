#include <iostream>
#include <vector>
using namespace std;
using mypair = pair<int, int>;

int TC, N, M, W;
int S, E, T;
vector<vector<mypair>> edges;
vector<int> dist;

void do_bellman_ford(void) {
	dist[1] = 0;
	for (int i = 1; i < N; ++i) {
		for (int from = 1; from < edges.size(); ++from) {
			for (int j = 0; j < edges[from].size(); ++j) {
				int to = edges[from][j].first;
				int time = edges[from][j].second;

				if (dist[to] > dist[from] + time) {
					dist[to] = dist[from] + time;
				}
			}
		}
	}

	for (int from = 1; from < edges.size(); ++from) {
		for (int j = 0; j < edges[from].size(); ++j) {
			int to = edges[from][j].first;
			int time = edges[from][j].second;

			if (dist[to] > dist[from] + time) {
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> TC;
	for (int i = 0; i < TC; ++i) {
		cin >> N >> M >> W;
		dist = vector<int>(N + 1, 987654321);
		edges = vector<vector<mypair>>(N + 1);

		for (int j = 0; j < M; ++j) {
			cin >> S >> E >> T;
			edges[S].push_back({ E, T });
			edges[E].push_back({ S, T });
		}
		for (int j = 0; j < W; ++j) {
			cin >> S >> E >> T;
			edges[S].push_back({ E, -T });
		}
		do_bellman_ford();
	}

	return 0;
}