import sys
from collections import deque

INF = int(1e9)
n, m, X, Y = map(int, sys.stdin.readline().strip().split())
graph = [[] for _ in range(1001)]

for _ in range(m):
    u, v = map(int, sys.stdin.readline().strip().split())
    graph[u].append(v)
    graph[v].append(u)

if not len(graph[X]):
    print(-1)
    exit(0)

vis = [[INF, INF] for _ in range(1001)]
vis[X][0] = 0
q = deque()
q.append((X, 0))

while q:
    now, cnt = q.popleft()

    for i in graph[now]:
        _cnt = cnt + 1
        if vis[i][_cnt % 2] != INF:
            continue

        vis[i][_cnt % 2] = cnt
        q.append((i, _cnt))

ans = []
for i in range(1, n + 1):
    if vis[i][Y % 2] > Y:
        continue
    
    ans.append(i)
print(*ans)
