import sys

n, m = map(int, sys.stdin.readline().split())
INF = int(1e9)
distance = [[INF] * (n + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    distance[i][i] = 0

for _ in range(m):
    a, b, t = map(int, sys.stdin.readline().split())
    distance[a][b] = t

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])

x = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

result = []

for i in range(1, n + 1):
    tmp = []
    for j in arr:
        val = distance[j][i] + distance[i][j]
        if val >= INF:
            continue
        tmp.append(val)
    result.append(max(tmp))

min_val = min(result)

for i in range(len(result)):
    if result[i] == min_val:
        print(i + 1, end=" ")