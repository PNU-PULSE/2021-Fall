#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, target, cnt = 0;
	cin >> n;
	vector<int> vec(n + 1);
	vec[0] = -1;
	for (int i = 0; i < n; ++i) {
		cin >> target;
		if (vec[cnt] < target)
			vec[++cnt] = target;
		else {
			vec[lower_bound(vec.begin(), vec.begin() + cnt, target) - vec.begin()] = target;
		}
	}

	cout << n - cnt;

	return 0;
}