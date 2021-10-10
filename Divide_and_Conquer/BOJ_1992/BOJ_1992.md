# 쿼드트리
![이미지](https://github.com/PNU-PULSE/2021-Fall/blob/main/Divide_and_Conquer/BOJ_1992/1.JPG?raw=true)

위 문제에서의 이미지 부분은 다음과 같이 풀 수 있다
![이미지](https://github.com/PNU-PULSE/2021-Fall/blob/main/Divide_and_Conquer/BOJ_1992/2.JPG?raw=true)

가장 큰 정사각형을 체크를 하는데 통일되어 있지않다면

4개의 정사각형으로 나누고 왼쪽위, 오른쪽위, 왼쪽아래, 오른쪽 아래순으로 하나씩 다시 검사를 하고

통일되어있지 않다면 다시 그 정사각형을 4개로 나누어 검사를 하는 방식이다


이해하기 쉽도록 위 이미지에서는 다음과 같이 표현했지만 실제 알고리즘에서는 다음 순서대로 사각형을 체크한다

(1)->(분할)->(1-1)->(1-2)->(분할)->(1-2-1)->(1-2-2)->(1-2-2)->(1-2-4)->(1-3-1)->(1-3-2)->(분할)


->(1-3-2-1)->(1-3-2-2)->(1-3-2-3)->(1-3-2-4)->(1-3-3)->(1-3-4)->(1-4)

그렇기에 해당이미지는 다음과 같이 표현된다
0(0011)(0(0111)01)1)

## 코딩
```python
def f(x, y, n):
    global ans
    quad = []
    for i in range(x, x + n):  # 해당 사각형의 범위에 해당하는 데이터를 quad에 옮김
        for j in range(y, y + n):
            k = li[j][i]
            if k == '1':
                quad.append('1')
            else:
                quad.append('0')
    check = quad[0]
    TF = True

    for i in quad:
        if check != i:  # 통일 X인 경우
            ans.append('(')
            f(x, y, n // 2)  # 왼쪽 위
            f(x + n // 2, y, n // 2)  # 오른쪽 위
            f(x, y + n // 2, n // 2)  # 왼쪽 아래
            f(x + n // 2, y + n // 2, n // 2)  # 오른쪽 아래
            ans.append(')')
            TF = False
            break
    if TF:  # 최종적으로 통일 되어 있는 경우
        ans.append(check)


N = int(input())
li = [list(input().strip()) for x in range(N)]

ans = []
f(0, 0, N)
for i in ans:
    print(i, end='')
