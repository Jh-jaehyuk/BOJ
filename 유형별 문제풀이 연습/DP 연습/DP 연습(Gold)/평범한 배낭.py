import sys

n, k = map(int, sys.stdin.readline().split())
arr = [[0, 0]] + [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
d = [[0] * (k + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    for j in range(1, k + 1):
        w = arr[i][0]
        v = arr[i][1]

        if j < w:
            d[i][j] = d[i - 1][j]
        else:
            d[i][j] = max(d[i - 1][j], d[i - 1][j - w] + v)

print(d[n][k])
