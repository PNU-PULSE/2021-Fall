import sys


def f():
    k = int(sys.stdin.readline())
    f = []
    s = []
    for i in range(k):
        h = ([int(x) for x in sys.stdin.readline().strip().split()])
        f.append(h[0])  # 서류심사순위
        s.append(h[1])  # 면접심사순위
    l1 = [0 for i in range(k)]
    l2 = [0 for i in range(k)]
    for i in range(k):
        l1[f[i] - 1] = s[i]  # 서류순위순으로 면접순위 정렬
        l2[s[i] - 1] = f[i]  # 면접순위순으로 서류순위 정렬
    for i in range(1, k):
        lev = l1[i - 1]  # 서류 i등의 면접 순위
        if i == 1:
            hl = lev
            cnt = hl
            continue
        if hl > lev:
            for x in range(lev + 1, hl):
                if l2[x - 1] > i:
                    cnt = cnt - 1
            hl = lev  # hl은 지금까지 기준이 된 지원자 중 가장 높은 면접순위
    print(cnt)


n = int(sys.stdin.readline())
for i in range(n):
    f()
