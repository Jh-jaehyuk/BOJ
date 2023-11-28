import sys

n, m = map(int, sys.stdin.readline().split())
INF = int(1e9)
distance = [[INF] * (n + 1) for _ in range(n + 1)]
result = [[str(i) for i in range(n + 1)] for _ in range(n + 1)]

for i in range(1, n + 1):
    distance[i][i] = 0
    result[i][i] = "-"

for _ in range(m):
    u, v, c = map(int, sys.stdin.readline().split())
    distance[u][v] = min(distance[u][v], c)
    distance[v][u] = min(distance[v][u], c)

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if distance[i][k] + distance[k][j] < distance[i][j]:
                distance[i][j] = distance[i][k] + distance[k][j]
                result[i][j] = result[i][k]

for i in range(1, n + 1):
    print(' '.join(result[i][1:]))