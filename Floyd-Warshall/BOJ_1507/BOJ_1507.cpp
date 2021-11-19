#include <iostream>
#include <vector>

using namespace std;

int N, ans = 0;
vector<vector<int>> len;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int inp;
    for(int i = 0; i < N; ++i) {
        vector<int> xlen;
        for(int j = 0; j < N; ++j) {
            cin >> inp;
            xlen.push_back(inp);
        }
        len.push_back(xlen);
    }
}

void solve() {
    for(int i = 0; i < N; ++i) {
        for(int j = i+1; j < N; ++j) {
            int k;
            for(k = 0; k < N; ++k) {
                if(k == i || k == j) continue;
                if(len[i][k] + len[k][j] == len[i][j]) break;
                else if(len[i][k] + len[k][j] < len[i][j]) ans = -20000000;
            }
            if(ans < 0) break;
            if(k == N) ans+= len[i][j];
        }
        if(ans < 0) break;
    }

    if(ans < 0) ans = -1;
    cout << ans;
}

int main()
{
    input();
    solve();
    return 0;
}