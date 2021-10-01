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
\*************  2021-10-01 14:15:10  *************/

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

int n, k;
vector<pair<double, double>> pos; // <x, y>

bool CanBeCost(double max_dist) {
    int tunnel_num = 1;
    double min_pos, max_pos;
    min_pos = max_pos = pos[0].second;

    for (int i = 1; i < n; i++) {
        double dist_to_min = abs(min_pos - pos[i].se);
        double dist_to_max = abs(max_pos - pos[i].se);
        if (max(dist_to_min, dist_to_max) / 2.0 > max_dist) {
            tunnel_num++;
            min_pos = max_pos = pos[i].second;
        }
        else {
            min_pos = min(min_pos, pos[i].second);
            max_pos = max(max_pos, pos[i].second);
        }
    }

    return tunnel_num <= k;
}

void Solve(void) {
    double lo = 0.0;
    double hi = 2e8;
    while ((hi - lo) >= 0.1) {
        double mid = (lo + hi) / 2.0;
        if (CanBeCost(mid))
            hi = mid;
        else
            lo = mid;
    }
    cout << fixed;
    cout.precision(1);
    cout << lo << endl;
}

void Init(void) {
    cin >> n >> k;
    pos.clear();
    resize(pos, n);
    for (auto& dot : pos) {
        cin >> dot.fi >> dot.se;
    }
    sort(pos);
}

int main(void) {
    Boost;
    int T; cin >> T;
    while (T--) {
        Init();
        Solve();
    }
    return 0;
}