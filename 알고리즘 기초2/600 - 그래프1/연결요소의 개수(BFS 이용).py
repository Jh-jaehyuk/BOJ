import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(n + 1)]
visited = [False] * 1001

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

count = 0

def bfs(graph, start, visited):
    queue = deque([start])
    visited[start] = True

    while queue:
        x = queue.popleft()
        for i in graph[x]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True

for i in range(1, n + 1):
    if not visited[i]:
        bfs(graph, i, visited)
        count += 1

print(count)
