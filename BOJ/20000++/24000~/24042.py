import sys
import heapq

n, m = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(n + 1)]
INF = int(1e12)
distance = [INF] * (n + 1)

for i in range(m):
    u, v = map(int, sys.stdin.readline().split())
    graph[u].append((v, i))
    graph[v].append((u, i))


def dijkstra(start):
    queue = []
    heapq.heappush(queue, (0, start))
    distance[start] = 0

    while queue:
        now_cost, now_node = heapq.heappop(queue)

        if distance[now_node] < now_cost:
            continue

        for next_node, next_cost in graph[now_node]:
            if now_cost % m > next_cost:
                cost = now_cost + m + next_cost - (now_cost % m) + 1
            else:
                cost = now_cost + next_cost - (now_cost % m) + 1

            if distance[next_node] <= cost:
                continue

            distance[next_node] = cost
            heapq.heappush(queue, (cost, next_node))


dijkstra(1)
print(distance[n])