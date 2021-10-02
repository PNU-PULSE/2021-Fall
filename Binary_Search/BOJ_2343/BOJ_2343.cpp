#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int numVideo, numBlueRay;
	cin >> numVideo >> numBlueRay;

	vector<ll> videos(numVideo);
	ll high = 0, low = -1;

	for (int i = 0; i < numVideo; i++) {
		ll value;
		cin >> value;
		videos.at(i) = value;
		high += value;
		low = max(low, value);
	}

	while (low <= high) {
		ll mid = (low + high) / 2; // 블루레이 크기
		ll blueRayCount = 0;
		ll videoSum = 0;

		for (const auto v : videos) {
			if (videoSum + v> mid) {
				blueRayCount++;
				videoSum = 0;
			}
			videoSum += v;
		}
		if (videoSum != 0) blueRayCount++; // mid보다 작아서 증가 못했을 때

		if (blueRayCount <= numBlueRay) high = mid - 1;
		else							low = mid + 1;
	}
	cout << low;
	return 0;
}