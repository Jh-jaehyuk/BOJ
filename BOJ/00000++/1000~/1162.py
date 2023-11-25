import sys
import heapq

n, m, k = map(int, sys.stdin.readline().split())
INF = int(1e18)
graph = [[] for _ in range(n + 1)]
distance = [[INF] * (k + 1) for _ in range(n + 1)]

for _ in range(m):
    u, v, c = map(int, sys.stdin.readline().split())
    graph[u].append((v, c))
    graph[v].append((u, c))

def dijkstra(start):
    queue = []
    heapq.heappush(queue, (0, 0, start))

    for i in range(k + 1):
        distance[start][i] = 0

    while queue:
        now_cost, now_count, now_node = heapq.heappop(queue)

        if distance[now_node][now_count] < now_cost:
            continue

        for next_node, next_cost in graph[now_node]:
            if now_count < k:
                if distance[next_node][now_count + 1] > now_cost:
                    distance[next_node][now_count + 1] = now_cost
                    heapq.heappush(queue, (now_cost, now_count + 1, next_node))

            if distance[next_node][now_count] <= now_cost + next_cost:
                continue

            distance[next_node][now_count] = now_cost + next_cost
            heapq.heappush(queue, (now_cost + next_cost, now_count, next_node))


dijkstra(1)
print(min(distance[n]))