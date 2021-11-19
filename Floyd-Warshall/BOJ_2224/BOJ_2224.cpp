#include <iostream>
#include <string>
#include <vector>
using namespace std;

int map[52][52];
int INF = 999999;

int main() {
	int N;	cin >> N;
	cin.ignore();

	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			map[i][j] = INF;
		}
	}

	while (N--){
		string s;
		getline(cin, s);
		vector<char> tmp;
		tmp.push_back(s[0]);
		tmp.push_back(s[5]);
		vector<int> vec;
		for (int i = 0; i < 2; i++) {
			if (tmp[i] >= 'A' && tmp[i] <= 'Z') {
				vec.push_back(tmp[i] - 65);
			}
			else if (tmp[i] >= 'a' && tmp[i] <= 'z') {
				vec.push_back(tmp[i] - 71);
			}
		}
		int from = vec[0];
		int to = vec[1];
		map[from][to] = abs(from-to);
	}

	
	for (int mid = 0; mid < 52; mid++) {
		for (int start = 0; start < 52; start++) {
			for (int end = 0; end < 52; end++) {
				if (map[start][end] > map[start][mid] + map[mid][end]) {
					map[start][end] = map[start][mid] + map[mid][end];
				}
			}
		}
	}

	vector<pair<char, char>> v;

	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			if (map[i][j] < INF) {
				int ii = i;
				int jj = j;
				if (ii >= 0 && ii <= 25)
					ii += 'A';
				else
					ii += 'G';
				if (jj >= 0 && jj <= 25)
					jj += 'A';
				else
					jj += 'G';
				if (ii == jj)
					continue;
				v.push_back({ ii,jj });
			}
		}
	}

	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << char(v[i].first) << " => " << char(v[i].second) << "\n";
	}

	return 0;
}
