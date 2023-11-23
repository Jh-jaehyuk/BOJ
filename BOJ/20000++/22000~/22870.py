import sys
import heapq

n, m = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(n + 1)]
INF = int(1e10)
distance = [INF] * (n + 1)
visited = [False] * (n + 1)

for _ in range(m):
    u, v, c = map(int, sys.stdin.readline().split())
    graph[u].append((v, c))
    graph[v].append((u, c))

for i in range(1, n + 1):
    graph[i].sort()

start, end = map(int, sys.stdin.readline().split())


def dijkstra(start):
    queue = []
    heapq.heappush(queue, (0, start))
    distance[start] = 0

    while queue:
        now_cost, now_node = heapq.heappop(queue)

        if distance[now_node] < now_cost:
            continue

        for next_node, next_cost in graph[now_node]:
            cost = now_cost + next_cost

            if visited[next_node]:
                continue

            if distance[next_node] <= cost:
                continue

            distance[next_node] = cost
            heapq.heappush(queue, (cost, next_node))


def find_path(start, end):
    now = start
    cost = 0
    while now != end:
        for next_node, next_cost in graph[now]:
            if visited[next_node]:
                continue
            if cost + next_cost + distance[next_node] == distance[start]:
                cost += next_cost
                now = next_node
                visited[next_node] = True
                break


dijkstra(end)
result = distance[start]
find_path(start, end)
distance = [INF] * (n + 1)
visited[end] = False
dijkstra(start)
result += distance[end]

print(result)
