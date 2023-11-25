import sys
import heapq

n, m, k = map(int, sys.stdin.readline().split())
INF = int(1e11)
start, end = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(n + 1)]
distance = [[INF] * (n + 1) for _ in range(n + 1)]

for _ in range(m):
    u, v, c = map(int, sys.stdin.readline().split())
    graph[u].append((v, c))
    graph[v].append((u, c))


def dijkstra(start):
    queue = []
    heapq.heappush(queue, (0, 0, start))
    distance[start][0] = 0

    while queue:
        now_cost, now_count, now_node = heapq.heappop(queue)

        for i in range(now_count):
            if distance[now_node][i] < now_cost:
                break

        else:
            for next_node, next_cost in graph[now_node]:
                cost = now_cost + next_cost

                if distance[next_node][now_count + 1] <= cost:
                    continue

                distance[next_node][now_count + 1] = cost
                heapq.heappush(queue, (cost, now_count + 1, next_node))


def get_minimum_value(p):
    min_val = INF
    for i in range(1, n + 1):
        min_val = min(min_val, distance[end][i] + (p * i))

    return min_val


dijkstra(start)
tmp = 0
for idx in range(k + 1):
    if idx == 0:
        print(get_minimum_value(tmp))
    else:
        p = int(sys.stdin.readline())
        tmp += p
        print(get_minimum_value(tmp))
