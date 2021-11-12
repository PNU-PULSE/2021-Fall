#include <iostream>
#include <vector>

using namespace std;
using mypair = pair<int, int>;

int N, M;
mypair step[] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
vector<vector<char>> vec;

int res = 987654321;
void tilt(vector<mypair> coins, int depth) {
	if (depth > 10)
		return;
	int out;
	mypair coin;
	vector<mypair> new_coins(2);
	for (int i = 0; i < 4; ++i) {
		out = 0;
		for (int j = 0; j < 2; ++j) {
			coin.first = coins[j].first + step[i].first;
			coin.second = coins[j].second + step[i].second;
			if (coin.first >= 0 && coin.first < N && coin.second >= 0 && coin.second < M) {
				if (vec[coin.first][coin.second] != '#') {
					new_coins[j] = coin;
				}
				else {
					new_coins[j] = coins[j];
				}
			}
			else {
				out += 1;
			}
		}
		if (out == 1)
			res = min(res, depth);
		else if (out == 0) {
			tilt(new_coins, depth + 1);
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	vec = vector<vector<char>>(N, vector<char>(M));
	vector<mypair> coins;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> vec[i][j];
			if (vec[i][j] == 'o')
				coins.push_back({ i, j });
		}
	}

	tilt(coins, 1);
	if (res != 987654321)
		cout << res;
	else
		cout << -1;



	return 0;
}