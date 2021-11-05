import sys


def f():
    k = int(sys.stdin.readline())
    f = []
    s = []
    for i in range(k):
        h = ([int(x) for x in sys.stdin.readline().strip().split()])
        f.append(h[0])
        s.append(h[1])
    l1 = [0 for i in range(k)]
    l2 = [0 for i in range(k)]
    for i in range(k):
        l1[f[i] - 1] = s[i]
        l2[s[i] - 1] = f[i]
    for i in range(1, k):
        lev = l1[i - 1]
        if i == 1:
            hl = lev
            k = hl
            continue
        if hl > lev:
            for x in range(lev + 1, hl):
                if l2[x - 1] > i:
                    k = k - 1
            hl = lev
    print(k)


n = int(sys.stdin.readline())
for i in range(n):
    f()
