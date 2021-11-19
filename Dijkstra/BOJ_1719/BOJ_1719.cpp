#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using mypair = pair<int, int>;

vector<vector<mypair>> vec;
int n, m;

void print_next_node(int start, vector<int>& trace) {
	int curr;
	for (int i = 0; i < n; ++i) {
		if (i == start) {
			cout << '-' << ' ';
			continue;
		}
		if (trace[i] == start) {
			curr = i;
		}
		else {
			curr = i;
			while (trace[curr] != start) {
				curr = trace[curr];
			}
		}
		cout << curr + 1 << ' ';
	}
	cout << '\n';
}

void dijkstra(int start) {
	priority_queue <mypair> pq;
	pq.push({ 0, start });

	vector<int> costs(n, 987654321);
	vector<int> trace(n, -1);

	int curr, dist;
	int next, next_dist;

	while (!pq.empty()) {
		dist = - pq.top().first;
		curr = pq.top().second;
		pq.pop();

		if (costs[curr] < dist)
			continue;
		for (int i = 0; i < vec[curr].size(); ++i) {
			next = vec[curr][i].first;
			next_dist = dist + vec[curr][i].second;

			if (costs[next] > next_dist) { 
				costs[next] = next_dist;
				trace[next] = curr;
				pq.push({ -next_dist, next });
			}
		}
	}

	print_next_node(start, trace);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;

	vec = vector<vector<mypair>>(n);

	int start, end, cost;
	for (int i = 0; i < m; ++i) {
		cin >> start >> end >> cost;
		vec[start - 1].push_back({ end - 1, cost });
		vec[end - 1].push_back({ start - 1, cost });
	}
	   
	for (int i = 0; i < n; ++i) {
		dijkstra(i);
	}

	return 0;
}
