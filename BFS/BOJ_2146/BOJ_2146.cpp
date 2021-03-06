#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

using mypair = pair<int, int>;

int MAP[100][100];
bool VISITED[100][100];
int N;
int res = 987654321;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void make_label(int a, int b, int curr_label) {
	VISITED[a][b] = true;
	queue<mypair> next_steps;
	next_steps.push({ a, b });
	MAP[a][b] = curr_label;

	while (!next_steps.empty()) {
		int x = next_steps.front().first;
		int y = next_steps.front().second;
		next_steps.pop();
		for (int i = 0; i < 4; ++i) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && !VISITED[next_x][next_y] && MAP[next_x][next_y] == -1) {
				VISITED[next_x][next_y] = true;
				MAP[next_x][next_y] = curr_label;
				next_steps.push({ next_x, next_y });
			}
		}
	}
}

void find_minimum(int curr_label) {
	queue<mypair> q;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (MAP[i][j] == curr_label) {
				q.push({ i,j });
				VISITED[i][j] = true;
			}
		}
	}

	int step = 0;
	while (!q.empty()) {
		const int land_size = q.size();
		for (int i = 0; i < land_size; ++i) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int j = 0; j < 4; ++j) {
				int next_x = x + dx[j];
				int next_y = y + dy[j];
				if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && !VISITED[next_x][next_y]) {
					if (MAP[next_x][next_y] == 0) {
						VISITED[next_x][next_y] = 1;
						q.push({ next_x,next_y });
					}
					else {
						if (step < res)
							res = step;
						return;
					}
				}
			}
		}
		++step;
		if (step > res)
			return;
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	queue<mypair> land;

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> MAP[i][j];
			if (MAP[i][j]) {
				MAP[i][j] = -1;
				land.push({ i, j });
			}
		}
	}

	int label = 1;
	while (!land.empty()) {
		if (!VISITED[land.front().first][land.front().second]) {
			make_label(land.front().first, land.front().second, label++);
		}
		land.pop();
	}

	for (int i = 1; i < label; ++i) {
		memset(VISITED, false, sizeof(VISITED));
		find_minimum(i);
	}
	cout << res;

	return 0;
}