import sys

n, m, q = map(int, sys.stdin.readline().split())
arr = [0] + list(map(int, sys.stdin.readline().split()))
narr = [0] * (n + 1)
for idx, val in enumerate(arr):
    narr[idx] = (val, idx)
narr.sort()

INF = int(1e10)
distance = [[INF] * (n + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    distance[i][i] = 0

for _ in range(m):
    a, b, d = map(int, sys.stdin.readline().split())
    distance[a][b] = min(distance[a][b], d)
    distance[b][a] = min(distance[b][a], d)

result = [[INF] * (n + 1) for _ in range(n + 1)]

for idx in range(1, n + 1):
    val, k = narr[idx]
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])
            result[i][j] = min(result[i][j], distance[i][k] + distance[k][j] + max(arr[i], arr[j], val))

for _ in range(q):
    s, t = map(int, sys.stdin.readline().split())
    print(-1 if result[s][t] == INF else result[s][t])