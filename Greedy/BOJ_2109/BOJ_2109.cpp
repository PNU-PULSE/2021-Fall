#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v(10001);

int main() {
	int N;	cin >> N;

	while (N--) {
		int pay, day;
		cin >> pay >> day;
		v[day].push_back(pay);
	}

	vector<int> v2;

	int total = 0;
	for (int i = 0; i < 10001; i++) {
		if (v[i].size() != 0) {
			for (int j = 0; j < v[i].size(); j++) {
				v2.push_back(v[i][j]);
				total += v[i][j];
			}
			while (v2.size() > i) {
				vector<int>::iterator iter = min_element(v2.begin(), v2.end());
				total -= *iter;
				v2.erase(iter);
			}
		}
	}

	cout << total;

	return 0;
}
