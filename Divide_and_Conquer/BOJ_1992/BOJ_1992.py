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
