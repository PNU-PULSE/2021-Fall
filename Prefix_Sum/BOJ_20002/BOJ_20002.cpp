#include <iostream>
#include <algorithm>
using namespace std;

int map[301][301];	
int DP[301][301];	


int main() {
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);

	int N;	cin >> N;

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			cin >> map[x][y];
			DP[x][y] = DP[x - 1][y] + DP[x][y - 1] - DP[x - 1][y - 1] + map[x][y];	// (1,1)부터 (x,y)까지의 누적합 구하기
		}
	}

	int MAX = map[1][1];


	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			for (int k = 0; k <= N; k++) {
				if (x + k <= N && y + k <= N) {
					int tmp = DP[x + k][y + k] - DP[x - 1][y + k] - DP[x + k][y - 1] + DP[x - 1][y - 1];
					MAX = max(MAX, tmp);
				}
			}
		}
	}


	cout << MAX;

	return 0;
}
