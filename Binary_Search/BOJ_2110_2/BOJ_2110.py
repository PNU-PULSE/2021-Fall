f = [int(x) for x in input().strip().split()]
n = f[0]
c = f[1]
li = []
for i in range(n):
    k = int(input())
    li.append(k)    # x좌표 li에 입력

li = sorted(li)  # li 오름차순 정렬

X = li[n - 1]  # x좌표 최댓값
x = li[0]  # x좌표 최솟값
lo = 1
hi = (X - x) // (c - 1)  # 공유기간 거리의 최댓값

while (lo <= hi):
    mid = (lo + hi) // 2
    point = x
    cnt = 1

    for i in li:
        dis = i - point
        if dis != 0:
            if mid <= dis:
                cnt += 1
                point = i

    if (cnt >= c):      # 공유기를 c개 이상 설치시
        ans = mid
        lo = mid + 1
    else:
        hi = mid - 1
print(ans)
