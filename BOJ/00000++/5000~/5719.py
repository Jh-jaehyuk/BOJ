import sys
import heapq
from collections import deque

INF = int(1e9)


def solve(n, m):
    start, end = map(int, sys.stdin.readline().split())
    graph = [[] for _ in range(n)]
    rev_graph = [[] for _ in range(n)]
    visited = [[False] * n for _ in range(n)]
    distance = [INF] * n

    for _ in range(m):
        u, v, c = map(int, sys.stdin.readline().split())
        graph[u].append((v, c))
        rev_graph[v].append((u, c))

    def dijkstra(start):
        queue = []
        heapq.heappush(queue, (0, start))
        distance[start] = 0

        while queue:
            now_cost, node = heapq.heappop(queue)

            if distance[node] < now_cost:
                continue

            for next_node, next_cost in graph[node]:
                _cost = now_cost + next_cost

                if distance[next_node] <= _cost:
                    continue

                if visited[node][next_node]:
                    continue

                distance[next_node] = _cost
                heapq.heappush(queue, (_cost, next_node))

    def find_path(end):
        queue = deque()
        queue.append(end)

        while queue:
            node = queue.popleft()

            if node == start:
                continue

            for next_node, next_cost in rev_graph[node]:
                if distance[node] == distance[next_node] + next_cost and not visited[next_node][node]:
                    visited[next_node][node] = True
                    queue.append(next_node)

    dijkstra(start)
    find_path(end)
    distance = [INF] * n
    dijkstra(start)

    print(-1 if distance[end] == INF else distance[end])


while True:
    n, m = map(int, sys.stdin.readline().split())

    if n == 0 and m == 0:
        break

    solve(n, m)
