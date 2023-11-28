import sys

n, m, r = map(int, sys.stdin.readline().split())
items = [0] + list(map(int, sys.stdin.readline().split()))
INF = int(1e9)
distance = [[INF] * (n + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    distance[i][i] = 0

for _ in range(r):
    a, b, l = map(int, sys.stdin.readline().split())
    distance[a][b] = l
    distance[b][a] = l

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])

result = []

for i in range(1, n + 1):
    val = 0
    for j in range(1, n + 1):
        if distance[i][j] <= m:
            val += items[j]
    result.append(val)

print(max(result))