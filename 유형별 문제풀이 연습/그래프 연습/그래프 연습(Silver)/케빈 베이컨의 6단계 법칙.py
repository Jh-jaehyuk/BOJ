import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
graph = [set() for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].add(b)
    graph[b].add(a)

result = []

for i in range(1, n + 1):
    visited = [0] * (n + 1)
    queue = deque()
    queue.append(i)

    while queue:
        v = queue.popleft()

        for i in graph[v]:
            if not visited[i]:
                visited[i] = visited[v] + 1
                queue.append(i)
    result.append(sum(visited))

print(result.index(min(result)) + 1)
