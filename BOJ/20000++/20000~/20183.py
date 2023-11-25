import sys
import heapq

n, m, start, end, c = map(int, sys.stdin.readline().split())
INF = int(1e15)
graph = [[] for _ in range(n + 1)]
shame = [INF] * (n + 1)

for _ in range(m):
    u, v, w = map(int, sys.stdin.readline().split())
    graph[u].append((v, w))
    graph[v].append((u, w))


def dijkstra(start):
    queue = []
    heapq.heappush(queue, (0, start, 0))

    while queue:
        now_cost, now_node, now_shame = heapq.heappop(queue)

        if shame[now_node] < now_shame:
            continue

        for next_node, next_cost in graph[now_node]:
            cost = now_cost + next_cost

            if shame[next_node] <= max(now_shame, next_cost):
                continue

            if cost > c:
                continue

            next_shame = max(now_shame, next_cost)
            shame[next_node] = min(shame[next_node], next_shame)
            heapq.heappush(queue, (cost, next_node, shame[next_node]))


dijkstra(start)
print(-1 if shame[end] == INF else shame[end])