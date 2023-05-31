n, k = map(int, input().split())
d = [[0] * (k + 1) for _ in range(n + 1)]

for i in range(n + 1):
    d[i][0] = 1
for i in range(k + 1):
    d[i][i] = 1

for i in range(1, n + 1):
    for j in range(1, min(i, k + 1)):
        d[i][j] = d[i - 1][j] % 10007 + d[i - 1][j - 1] % 10007

print(d[n][k] % 10007)
