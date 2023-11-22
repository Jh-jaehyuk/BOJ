import sys
import heapq

n, m = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(n + 1)]
indegree = [0] * (n + 1)

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    indegree[b] += 1
    graph[a].append(b)

queue = []

for i in range(1, n + 1):
    if indegree[i] == 0:
        heapq.heappush(queue, i)
    graph[i].sort()

result = []

while queue:
    now = heapq.heappop(queue)
    result.append(now)

    for i in graph[now]:
        indegree[i] -= 1

        if indegree[i] == 0:
            heapq.heappush(queue, i)

print(*result)