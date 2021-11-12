#include <iostream>
using namespace std;

// 약을 먹는 경우 : 2가지, 한 알을 쪼개어 먹든가, 반 알을 먹든가.
// 한 알을 쪼개면 --> 반 알의 개수 증가
// 반 알을 먹으면 --> 반 알의 개수 감소
// 메모이제이션

long long DP[31][31];
//int find(int f, int s);

int main() {
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			if (i == 0)
				DP[i][j] = 1;
			else if (i != 0 && j == 0)
				DP[i][j] = DP[i - 1][1];
			else
				DP[i][j] = DP[i - 1][j + 1] + DP[i][j - 1];
		}
	}

	while (1) {
		int n;	cin >> n;
		if (n == 0) break;
		cout << DP[n][0] << "\n";
		//cout << find(n, 0) << "\n";
	}

	return 0;
}

//int find(int f, int s) {
//	if (f == 0 && s != 0)
//		return 1;
//	if (f != 0 && s == 0)
//		return find(f - 1, 1);
//	return find(f - 1, s + 1) + find(f, s - 1);
//}

