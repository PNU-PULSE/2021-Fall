#include<iostream>
#include<array>
#include<algorithm>
using namespace std;

int N, K;
array<array<int , 100001>, 101> bag = {0,};
int main(){
  cin >> N >> K;
  int W, V;
  for(int i = 1; i <= N; ++i){
    cin >> W >> V;
    for(int j = 1; j <= K; ++j){
      if(j < W) bag[i][j] = bag[i-1][j];
      else bag[i][j] = max(bag[i-1][j], bag[i-1][j-W]+V);
    }
  }
  cout << bag[N][K];
}