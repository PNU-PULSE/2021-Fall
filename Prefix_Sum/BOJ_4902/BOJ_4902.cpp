/********* github.com/tykr0001/algorithm *********\
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*
*$*                                             *$*
*$*    ||||||||  ||    ||  ||   |||  |||||||    *$*
*$*       ||      ||  ||   || |||    ||    ||   *$*
*$*       ||        ||     |||       |||||||    *$*
*$*       ||        ||     || |||    ||  ||     *$*
*$*       ||        ||     ||   |||  ||   |||   *$*
*$*                                             *$*
*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*
\*************  2021-05-19 02:06:18  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;
using vvs = vector<vector<string>>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pair<int, int>>;
using vvpii = vector<vector<pair<int, int>>>;
using vpll = vector<pair<ll, ll>>;
using vvpll = vector<vector<pair<ll, ll>>>;
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fi first
#define se second
#define INF INT32_MAX
#define LINF INT64_MAX
#define endl '\n'
#define rep(i,beg,end) for(int i=beg; i<end; i++)
template<class T>
void sort(T& container) { sort(container.begin(), container.end()); }
template<class T1, typename T2>
void sort(T1& container, T2 cmp) { sort(container.begin(), container.end(), cmp); }
template<class T1, class T2>
istream& operator>>(istream& is, pair<T1, T2>& rhs) { is >> rhs.fi >> rhs.se; return is; }
template<class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& rhs) { os << rhs.fi << ' ' << rhs.se; return os; }
template<class T>
istream& operator>>(istream& is, vector<T>& rhs) { for (T& elem : rhs) is >> elem; return is; }
template<class T>
ostream& operator<<(ostream& os, const vector<T>& rhs) { for (const T& elem : rhs) os << elem << ' '; os << endl; return os; }
template<class T>
void resize(T& container, int _size) { container.resize(_size); }
template<class T, typename... Size>
void resize(T& container, int _size, Size... _sizes) { container.resize(_size); for (auto& elem : container) resize(elem, _sizes...); }
/*************************************************/

vector<vector<int>> prefix_sum;
int tc;
int n;
int ans;

void solve(void) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i * 2; j++) {
            int inp; cin >> inp;
            prefix_sum[i][j] = prefix_sum[i][j - 1] + inp;
        }
    }

    // triangle sum
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i * 2; j += 2) {
            for (int size = 0, triangle_sum = 0; size < n - i + 1; size++) {
                triangle_sum += prefix_sum[i + size][j + size * 2] - prefix_sum[i + size][j - 1];
                ans = max(ans, triangle_sum);
            }
        }
    }

    // reversed triangle sum
    for (int i = n; i >= 1; i--) {
        for (int j = 2; j < i * 2; j += 2) {
            for (int size = 0, reversed_triangle_sum = 0; size * 2 < j && j < (i - size) * 2; size++) {
                reversed_triangle_sum += prefix_sum[i - size][j] - prefix_sum[i - size][j - size * 2 - 1];
                ans = max(ans, reversed_triangle_sum);
            }
        }
    }

    cout << tc << ". " << ans << endl;
}

void init(void) {
    prefix_sum.clear();
    resize(prefix_sum, n + 1, n * 2);
    tc++;
    ans = INT_MIN;
}

int main(void) {
    Boost;
    while (1) {
        cin >> n; if (n == 0) break;
        init();
        solve();
    }
    return 0;
}