import sys
from collections import deque

n, m, v = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(n + 1)]
visited = [False] * 1001

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

for g in range(len(graph)):
    graph[g] = sorted(graph[g])

def dfs(graph, v, visited):
    visited[v] = True
    print(v, end=' ')

    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

def bfs(graph, v, visited):
    queue = deque([v])
    visited[v] = True
    while queue:
        x = queue.popleft()
        print(x, end=' ')

        for i in graph[x]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True

dfs(graph, v, visited)
print()
visited = [False] * 1001
bfs(graph, v, visited)
