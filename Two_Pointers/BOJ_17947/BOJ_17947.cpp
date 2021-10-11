#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int N, M, K;
int lastCard;
int GCY, cnt = 0;
vector<int> last(400000);
vector<int> card;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    int a = (4*N) / K;
    int b = (4*N) % K;
    fill(last.begin(), last.begin()+K, a);
    fill(last.begin()+1, last.begin()+b+1, a+1);

    for(int i = 0; i <= M; ++i) {
        cin >> a >> b;
        a %= K; b %= K;
        last[a]--;
        last[b]--;
    }
    GCY = abs(a - b);
}

void solve() {
    lastCard = 4*N - M*2 - 2;
    for(int i = 0; i < K; ++i) {
        for(int j = 0; j < last[i]; ++j) card.push_back(i);
    }

    int bg = 0, ed = lastCard / 2;
    int cai;

    while(ed < lastCard && cnt < M-1) {
        if(card[ed] - card[bg] <= GCY) {
            ed++;
        }
        else {
            cnt++;
            ed++;
            bg++;
        }
    }
}

void print() {
    cout << cnt;
}

int main()
{
    input();
    solve();
    print();
    return 0;
}