import sys


def f(x, y, n):
    global ans
    quad = []
    for i in range(x, x + n):
        for j in range(y, y + n):
            k = li[j][i]
            if k == '1':
                quad.append('1')
            else:
                quad.append('0')
    check = quad[0]
    TF = True

    for i in quad:
        if check != i:
            ans.append('(')
            f(x, y, n // 2)
            f(x + n // 2, y, n // 2)
            f(x, y + n // 2, n // 2)
            f(x + n // 2, y + n // 2, n // 2)
            ans.append(')')
            TF = False
            break
    if TF:
        ans.append(check)


N = int(sys.stdin.readline())
li = [list(sys.stdin.readline().strip()) for x in range(N)]

ans = []
f(0, 0, N)
for i in ans:
    print(i, end='')
