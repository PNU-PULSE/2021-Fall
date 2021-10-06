//개똥벌레
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// 정렬, 누적합, 이진탐색
// int N, H, temp;

// int main(){
//   vector<int> up(500001); // 종유석
//   vector<int> down(500001); //석순
//   vector<int> ans(500001);
//   cin >> N >> H;
//   for(int i = 0; i < N; ++i){
//     cin >> temp;
//     if(i % 2 == 0) down[temp] += 1;
//     else up[temp] += 1;
//   }
//   int min_ = 500000;
//   int _up = 0;
//   int _down = N/2;
//   for(int i = 1; i <= H; ++i){
//     ans[i] = _down + _up;
//     _down -= down[i];
//     _up += up[H-i];
//     min_ = min(min_, ans[i]);
//   }

//   int cnt = count(ans.begin()+1, ans.begin()+H+1, min_);
//   cout << min_ << ' ' << cnt;
// }

#include<iostream>
#include<algorithm>
using namespace std;
int N, H, tmp, ans = 500001, cnt = 0;
int up [100001] = {0,};
int down [100001] = {0,};

int main(){
  cin >> N >> H;
  for(int i = 1; i <= N/2; ++i){
    cin >> down[i] >> up[i];
  }
  // 1 ~ N/2
  sort(up+1, up+(N/2)+1);
  sort(down+1, down+(N/2)+1);

  for(int i = 1; i <= H; ++i){
    // i 보다 크거나 같은 경우 첫번째
    tmp = lower_bound(down+1, down+(N/2)+1, i) - (down+1);
    // i 를 초과하는 경우 첫번째
    tmp += upper_bound(up+1, up+(N/2)+1, H-i) - (up+1); 
    tmp = N - tmp; // 부딪히는 갯수

    if(ans == tmp) cnt ++;
    else if(ans > tmp){
      ans = tmp;
      cnt = 1;
    }

  }
  cout << ans << ' ' << cnt;
  return 0;
}