//
//  main.cpp
//  BOJ_14927
//
//  Created by Coby Kim on 2021/11/06.
//

#include <iostream>
#include <algorithm>
using namespace std;


const int MAX = 18;
const int INF = 987654321;

int N;
int bulb[MAX];
int simulation[MAX];

//XOR를 이용해 전구 상태 바꿈
void pressSwitch(int y, int x) {

    //자기 자신
    simulation[y] ^= (1 << (N - x - 1));

    //위
    if (y) simulation[y - 1] ^= (1 << (N - x - 1));

    //아래
    if (y != N - 1) simulation[y + 1] ^= (1 << (N - x - 1));

    //왼
    if (x) simulation[y] ^= (1 << (N - x));

    //오
    if (x != N - 1) simulation[y] ^= (1 << (N - x - 2));
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 속도 향상 위해

    cin >> N;

    //각 행을 비트로 입력

    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {
            int temp;
            cin >> temp;
            if (temp) bulb[i] |= 1 << j;
        }
    }

    int result = INF;

    // 첫 row 2 ^ N의 경우 모두 확인
    for (int candidate = (1 << N) - 1; candidate >= 0; candidate--) {
        int press = 0;

        for (int i = 0; i < N; i++) {
            simulation[i] = bulb[i];
        }
        
        //첫 x 2 ^ N의 경우 모두 확인
        for (int x = 0; x < N; x++) {
            if (candidate&(1 << x)) {
                pressSwitch(0, x);
                press++;                
            }
        }

        //이후에 (y - 1)행들의 전구를 다 끄기 위해
        for (int y = 1; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (simulation[y - 1] & (1 << (N - x - 1))) {                                  pressSwitch(y, x);
                    press++;
                }
            }
        }

        //N-2행까지의 전구를 모두 껐으므로 N-1행의 전구들이 다 꺼져있으면 전부 꺼져있다.
        if (simulation[N - 1] == 0) result = min(result, press);
    }
    
    if (result == INF) cout << -1 << endl;
    else cout << result << endl;

    return 0;
}
