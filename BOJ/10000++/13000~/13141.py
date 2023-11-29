import sys

n, m = map(int, sys.stdin.readline().split())
INF = int(1e9)
edges = []
distance = [[INF] * (n + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    distance[i][i] = 0

for _ in range(m):
    s, e, l = map(int, sys.stdin.readline().split())
    distance[s][e] = min(distance[s][e], l)
    distance[e][s] = min(distance[e][s], l)
    edges.append((s, e, l))

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])

result = INF
for i in range(1, n + 1):
    val = 0
    for edge in edges:
        s, e, l = edge
        val = max(val, (distance[i][s] + distance[e][i] + l) / 2)
    result = min(result, val)

print(f"{result:.1f}")