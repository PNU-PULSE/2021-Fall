#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned long long int llt;
int N;
vector<int> works;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int a;
    for(int i = 0; i < N; ++i) {
        cin >> a;
        works.push_back(a);
    }
    sort(works.begin(), works.end());
}

void solve1() {
    int k = works[0];
    for(int i = 1; i < N; ++i) {
        if((i+1)*k > works[i]) {
            k = works[i] / (i+1);
        }
    }
    cout << k;
}

int main()
{
    input();
    solve1();
    return 0;
}