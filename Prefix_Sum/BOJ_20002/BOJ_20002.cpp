#include <iostream>
#include <algorithm>
using namespace std;

int map[301][301];	// 300 * 300,  index는 1부터 시작
int DP[301][301];	// 누적합

// 누적합(구간합)에서 정사각형인지만 check 하면 될거 같은데.. + max값 구하기

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

	// (a,b) ~ (x,y) '구간합' ('누적합'을 이용해서 '구간합' 구하기)
	// 정사각형이 되도록 구간을 어떻게 줄 것이냐.. ->  K 활용
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
