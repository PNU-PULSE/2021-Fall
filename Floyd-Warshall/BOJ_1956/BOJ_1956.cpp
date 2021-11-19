#include <iostream>
using namespace std;

int map[401][401];
int INF = 999999;

int main() {
	int v, e;	
	cin >> v >> e;

	//fill(map[0], map[400], INF);

	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			map[i][j] = INF;
		}
	}


	for (int i = 0; i < e; i++) {
		int from, to, dis;
		cin >> from >> to >> dis;
		map[from][to] = dis;
	}

	for (int mid = 1; mid <= v; mid++) {
		for (int start = 1; start <= v; start++) {
			for (int end = 1; end <= v; end++) {
				if (map[start][end] > map[start][mid] + map[mid][end]) {
					map[start][end] = map[start][mid] + map[mid][end];
				}
			}
		}
	}

	int dis = INF;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (dis > map[i][j] + map[j][i])
				dis = map[i][j] + map[j][i];
		}
	} 

	if (dis < INF)
		cout << dis;
	else
		cout << "-1";

	return 0;
}
