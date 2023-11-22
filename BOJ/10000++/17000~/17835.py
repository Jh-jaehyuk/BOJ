import sys
import heapq
from collections import defaultdict

n, m, k = map(int, sys.stdin.readline().split())
INF = int(1e12)
graph = [[] for _ in range(n + 1)]
weight = defaultdict(int)
distance = [INF] * (n + 1)

for _ in range(m):
    u, v, c = map(int, sys.stdin.readline().split())
    graph[v].append(u)

    if weight[(v, u)] == 0:
        weight[(v, u)] = c
    else:
        weight[(v, u)] = min(weight[(v, u)], c)

place = list(map(int, sys.stdin.readline().split()))


def dijkstra(start):
    queue = []

    for i in start:
        heapq.heappush(queue, (0, i))
        distance[i] = 0

    while queue:
        dist, now = heapq.heappop(queue)

        if distance[now] < dist:
            continue

        for i in graph[now]:
            if not weight[(now, i)]:
                continue

            cost = dist + weight[(now, i)]

            if cost < distance[i]:
                distance[i] = cost
                heapq.heappush(queue, (cost, i))


max_idx = -1
result = -1

dijkstra(place)

for i in range(1, n + 1):
    if distance[i] > result and distance[i] != INF:
        result = distance[i]
        max_idx = i

print(max_idx)
print(result)