#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

using pii = pair<int, int>;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> vec(N, vector<int>(M));
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<int> idx(N, 0);

	int curr_max = -1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> vec[i][j];
		}
		sort(vec[i].begin(), vec[i].end());
		pq.push({ vec[i][0], i });
		curr_max = max(vec[i][0], curr_max);
	}

	int res = 987654321;

	for (int i = 0; i < N * (M - 1); ++i) {
		pii top = pq.top();
		int curr_idx = top.second;
		res = min(res, curr_max - top.first);
		if (idx[curr_idx]++ == M - 1)
			break;
		else {
			pq.pop();
			curr_max = max(curr_max, vec[curr_idx][idx[curr_idx]]);
			pq.push({ vec[curr_idx][idx[curr_idx]], curr_idx });
		}
	}

	cout << res;


	return 0;
}