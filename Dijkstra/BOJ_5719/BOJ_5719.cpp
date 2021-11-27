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
\*************  2021-10-28 00:08:03  *************/

/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using v2i = vector<vi>;
using v3i = vector<v2i>;
using vb = vector<bool>;
using v2b = vector<vb>;
using vs = vector<string>;
using v2s = vector<vs>;
using vc = vector<char>;
using v2c = vector<vc>;
using vl = vector<ll>;
using v2l = vector<vl>;
using v3l = vector<v2l>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
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

int n, m;
int init, goal;
int ans;
vector<vector<pii>> graph;
vector<vector<int>> shortest_path;

int Dijkstra(void) {
    vector<int> dist;
    dist.resize(n, INF);
    dist[init] = 0;
    priority_queue<pii> pq; // < -cost, node > 
    pq.emplace(dist[init], init);

    while (!pq.empty()) {
        auto [c, src] = pq.top();
        pq.pop();

        if (dist[src] < -c)
            continue;

        for (auto& [dst, weight] : graph[src]) {
            if (weight == -1)
                continue;

            int cost = dist[src] + weight;

            if (cost < dist[dst]) {
                dist[dst] = cost;
                pq.emplace(-cost, dst);

                shortest_path[dst].clear();
                shortest_path[dst].emplace_back(src);
            }
            else if (cost == dist[dst]) {
                shortest_path[dst].emplace_back(src);
            }
        }
    }
    return dist[goal];
}

void BFS() {
    queue<int> q;
    vector<bool> visited;
    q.emplace(goal);
    resize(visited, n);

    while (!q.empty()) {
        int dst = q.front();
        q.pop();
        if (visited[dst]) continue;
        visited[dst] = true;
        for (auto src : shortest_path[dst]) {
            for (auto& [next, weight] : graph[src]) {
                if (next == dst)
                    weight = -1;
            }
            q.emplace(src);
        }
    }
};

void Solve(void) {
    if (n == 0 && m == 0) return;
    Dijkstra();
    BFS();
    ans = Dijkstra();
    cout << (ans != INF ? ans : -1) << endl;
}

void Init(void) {
    cin >> n >> m;
    if (n == 0 && m == 0) return;

    graph.clear();
    shortest_path.clear();
    resize(graph, n);
    resize(shortest_path, n);

    cin >> init >> goal;
    for (int i = 0; i < m; i++) {
        int u, v, p;
        cin >> u >> v >> p;
        graph[u].emplace_back(v, p);
    }
}

int main(void) {
    Boost;
    do {
        Init();
        Solve();
    } while (n != 0 && m != 0);
    return 0;
}