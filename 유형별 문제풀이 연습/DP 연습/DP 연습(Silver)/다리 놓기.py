T = int(input())

d = [[0] * 31 for _ in range(31)]
for i in range(31):
    d[i][0] = 1
    d[i][i] = 1

for i in range(1, 31):
    for j in range(1, min(i, 31)):
        d[i][j] = d[i - 1][j] + d[i - 1][j - 1]

for _ in range(T):
    n, m = map(int, input().split())
    print(d[m][n])
