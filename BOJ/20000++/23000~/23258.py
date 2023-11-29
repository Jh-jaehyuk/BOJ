import sys

n, q = map(int, sys.stdin.readline().split())
arr = [[0] * (n + 1)]
INF = int(1e10)

for _ in range(n):
    arr.append([0] + list(map(int, sys.stdin.readline().split())))

for i in range(n + 1):
    for j in range(n + 1):
        if i == j:
            continue
        if arr[i][j] == 0:
            arr[i][j] = INF

distance = [[[INF] * (n + 1) for i in range(n + 1)] for j in range(n + 1)]

for i in range(1, n + 1):
    for j in range(1, n + 1):
        distance[0][i][j] = arr[i][j]

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            distance[k][i][j] = min(distance[k - 1][i][j], distance[k - 1][i][k] + distance[k - 1][k][j])

for _ in range(q):
    C, s, e = map(int, sys.stdin.readline().split())
    print(-1 if distance[C - 1][s][e] == INF else distance[C - 1][s][e])
