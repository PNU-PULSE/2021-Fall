# LEET 42 Trapping Rain Water

![예시 이미지](https://github.com/PNU-PULSE/2021-Fall/blob/main/Dynamic_Programming/LEET_42/1.png)

이 문제는 i번째 지점에서 저장할 수 있는 물의 높이는 i번째 기준 좌측의 최고 높이의 벽과 <br>
우측의 최고 높이의 벽 중 작은 값이 바로 해당 위치에서 무을 저장할 수 있는 높이가 된다.

따라서 이를 이용해서
```
1. 각 위치별 촤측의 최고 높이 벽을 찾기
2. 각 위치별 우측의 최고 높이 벽을 찾기
```

위 2가지 과정을 거치면 쉽게 풀 수 있는 문제이다.

```C++
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_maximum(height.size());
        
        for(int i = 1; i < height.size(); ++i) {
            left_maximum[i] = max(left_maximum[i - 1], height[i - 1]);
        }
        
        int water = 0;
        int right_maximum = height[height.size() - 1];
        for(int i = height.size() - 2; i >= 0; --i) {
            water += max(min(left_maximum[i], right_maximum) - height[i], 0);
            
            right_maximum = max(right_maximum, height[i]);
        }
        
        return water;
    }
};
```
