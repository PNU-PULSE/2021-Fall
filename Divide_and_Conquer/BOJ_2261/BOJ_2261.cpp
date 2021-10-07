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
\*************  2021-10-04 10:29:26  *************/

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

vector<pair<ll, ll>> point; // <x, y>
int n;

ll CalcDist(const pll& a, const pll& b) {
    return (a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se);
}

bool CompY(const pll& a, const pll& b) {
    return a.se < b.se;
}

ll query(int left, int right) {
    // 종료조건
    if (right - left <= 2) {
        ll ret = INT64_MAX;
        for (int i = left; i <= right - 1; i++) {
            for (int j = i + 1; j <= right; j++) {
                ret = min(ret, CalcDist(point[i], point[j]));
            }
        }
        return ret;
    }

    // 분할정복
    int mid = (left + right) / 2;
    ll ret = min(query(left, mid), query(mid + 1, right));
    ll line = (point[mid].fi + point[mid + 1].fi) / 2;
    vector<pll> center;
    
    center.reserve(right - left + 1);
    for (int i = left; i <= right; i++) {
        if ((point[i].fi - line) * (point[i].fi - line) < ret)
            center.push_back(point[i]);
    }

    sort(center, [ ](const pll& a, const pll& b) {return a.se < b.se; });

    for (int i = 0; i < center.size(); i++) {
        for (int j = i + 1; j < center.size(); j++) {
            if ((center[i].se - center[j].se) * (center[i].se - center[j].se) < ret)
                ret = min(ret, CalcDist(center[i], center[j]));
            else
                break;
        }
    }

    return ret;
}

void Solve(void) {
    cout << query(0, n - 1) << endl;
}

void Init(void) {
    cin >> n;
    point.resize(n);
    cin >> point;
    sort(point); // sort(point.begin(), point.end());
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}