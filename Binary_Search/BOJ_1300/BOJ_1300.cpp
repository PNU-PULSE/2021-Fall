#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long int ll;
ll N, K;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
}

void solve() {
    ll low = 1, high = N*N;
    ll result = -1;
    while (low <= high){
        ll cnt = 0;
        ll mid = (low + high) / 2;
        for (ll i = 1; i <= N; i++)
            cnt += min(mid / i, N);

        if (cnt < K) low = mid + 1;
        else {
            result = mid;
            high = mid - 1;
        }

    }
    cout << result;
}

int main()
{
    input();
    solve();
    return 0;
}
