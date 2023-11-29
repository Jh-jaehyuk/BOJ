import sys

n, m, t = map(int, sys.stdin.readline().split())
INF = int(1e9)
distance = [[INF] * (n + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    distance[i][i] = 0

for _ in range(m):
    u, v, h = map(int, sys.stdin.readline().split())
    distance[u][v] = min(distance[u][v], h)

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            distance[i][j] = min(distance[i][j], max(distance[i][k], distance[k][j]))

for _ in range(t):
    s, e = map(int, sys.stdin.readline().split())
    print(-1 if distance[s][e] == INF else distance[s][e])