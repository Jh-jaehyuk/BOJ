import sys
import heapq

v, e = map(int, sys.stdin.readline().split())
k = int(sys.stdin.readline())
INF = int(1e9)
graph = [[] for _ in range(v + 1)]
visited = [False] * (v + 1)
distance = [INF] * (v + 1)

for _ in range(e):
    a, b, c = map(int, sys.stdin.readline().split())
    graph[a].append((b, c))

for node in graph:
    node.sort(key=lambda x: x[1])


def get_smallest_node():
    min_val = INF
    index = 0
    for i in range(1, v + 1):
        if distance[i] < min_val and not visited[i]:
            min_val = distance[i]
            index = i
    return index


def dijkstra(start):
    queue = []
    heapq.heappush(queue, (0, start))
    distance[start] = 0

    while queue:
        dist, now = heapq.heappop(queue)

        if distance[now] < dist:
            continue

        for i in graph[now]:
            cost = dist + i[1]

            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(queue, (cost, i[0]))


dijkstra(k)
for i in range(1, v + 1):
    if distance[i] == INF:
        print('INF')
    else:
        print(distance[i])
