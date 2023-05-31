import sys
import heapq

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
graph = [[] for _ in range(n + 1)]
INF = int(1e9)
visited = [False] * (n + 1)
distance = [INF] * (n + 1)

for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    graph[a].append((b, c))

start, end = map(int, sys.stdin.readline().split())

queue = []
heapq.heappush(queue, (0, start))
distance[start] = 0

while queue:
    dist, node = heapq.heappop(queue)
    if distance[node] < dist:
        continue
    for i, d in graph[node]:
        tmp_d = d + dist
        if distance[i] > tmp_d:
            distance[i] = tmp_d
            heapq.heappush(queue, (tmp_d, i))

print(distance[end])
