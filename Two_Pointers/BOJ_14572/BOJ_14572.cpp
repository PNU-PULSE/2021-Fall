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
\*************  2021-10-05 01:59:24  *************/

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

int n, k, d;
vector<pii> student; // <skill, algorithm>
vector<int> cnt_algorithm;

void Solve(void) {
    int lo = 0, hi = 0;
    ll ans = 0;

    while (hi < n) {
        ll all = 0;
        ll someone = 0;
        for (int i = 1; i <= k; i++) {
            if (student[hi].se & (1 << i))
                cnt_algorithm[i]++;
            if (cnt_algorithm[i] == hi - lo + 1)
                all++;
            if (cnt_algorithm[i] != 0)
                someone++;
        }

        ans = max(ans, (someone - all) * (hi - lo + 1));

        hi++;
        while (student[hi].fi - student[lo].fi > d) {
            for (int i = 1; i <= k; i++) {
                if (student[lo].se & (1 << i)) {
                    cnt_algorithm[i]--;
                }
            }
            lo++;
        }
    }

    cout << ans << endl;
}

void Init(void) {
    cin >> n >> k >> d;
    resize(student, n);
    resize(cnt_algorithm, k + 1);
    for (int i = 0; i < n; i++) {
        int num_algorithm;
        cin >> num_algorithm >> student[i].fi;
        for (int j = 0; j < num_algorithm; j++) {
            int algorithm;
            cin >> algorithm;
            student[i].se |= (1 << algorithm);
        }
    }
    sort(student, [ ](const pii& a, const pii& b) {return a.fi < b.fi; });
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}