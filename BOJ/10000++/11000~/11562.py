import sys

n, m = map(int, sys.stdin.readline().split())
INF = int(1e9)
distance = [[INF] * (n + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    distance[i][i] = 0

for _ in range(m):
    u, v, c = map(int, sys.stdin.readline().split())
    distance[u][v] = 0

    if c == 0:
        distance[v][u] = 1

    else:
        distance[v][u] = 0

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])

q = int(sys.stdin.readline())
for _ in range(q):
    s, e = map(int, sys.stdin.readline().split())
    print(distance[s][e])
