#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> inO;
vector<int> postO;
int N;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int c;
    for(int i = 0; i < N; ++i) {
        cin >> c;
        inO.push_back(c);
    }
    for(int i = 0; i < N; ++i) {
        cin >> c;
        postO.push_back(c);
    }
}

void DnQ(vector<int>::iterator inSt, vector<int>::iterator inEn, vector<int>::iterator poSt, vector<int>::iterator poEn) {
    cout << *(poEn-1) << " ";

    auto it = find(inSt, inEn, *(poEn-1));
    int gap = it - inSt;

    if(gap > 0) {
        DnQ(inSt, it, poSt, poSt+gap);
    }

    gap = inEn - it;
    if(gap > 1) {
        DnQ(it+1, inEn, poEn-gap, poEn-1);
    }
}

void solve() {
    DnQ(inO.begin(), inO.end(), postO.begin(), postO.end());
}

int main()
{
    input();
    solve();
    return 0;
}