import sys

n, m = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(n + 1)]


def dfs(v, e, d):
    global dist
    visited[v] = True

    if v == e:
        dist = d
        return

    for i in graph[v]:
        if not visited[i[0]]:
            dfs(i[0], e, d + i[1])


for _ in range(n - 1):
    a, b, c = map(int, sys.stdin.readline().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

for _ in range(m):
    v, e = map(int, sys.stdin.readline().split())
    visited = [False] * (n + 1)
    dist = 0
    dfs(v, e, 0)
    print(dist)
