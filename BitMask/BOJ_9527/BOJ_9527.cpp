#include <iostream>

using namespace std;

using ll = long long;

ll sum_of_ones(ll target) {
	ll add = 1, div = 2, res = 0;
	target = target + 1;
	
	while (add < target) {
		res += target / div * add + max(0ll, target % div - div / 2);
		div *= 2;
		add *= 2;
	}
	return res;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll a, b;
	cin >> a >> b;

	cout << sum_of_ones(b) - sum_of_ones(a - 1);

	return 0;
}