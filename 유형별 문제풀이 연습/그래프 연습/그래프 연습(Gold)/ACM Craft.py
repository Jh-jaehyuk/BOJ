import sys
from collections import deque

T = int(sys.stdin.readline())


def bfs(node):
    global start
    queue = deque()
    queue.append(node)
    time[node] = build[node]

    while queue:
        v = queue.popleft()
        if graph[v]:
            for i in graph[v]:
                if time[i] < time[v] + build[i]:
                    time[i] = time[v] + build[i]
                    queue.append(i)
        else:
            start.append(v)


for _ in range(T):
    N, K = map(int, sys.stdin.readline().split())
    build = [0] + list(map(int, sys.stdin.readline().split()))
    graph = [[] for _ in range(N + 1)]
    time = [0] * (N + 1)
    for _ in range(K):
        a, b = map(int, sys.stdin.readline().split())
        graph[b].append(a)
    W = int(sys.stdin.readline())
    start = []
    bfs(W)
    max_time = 0
    for node in start:
        if time[node] > max_time:
            max_time = time[node]
    print(max_time)
