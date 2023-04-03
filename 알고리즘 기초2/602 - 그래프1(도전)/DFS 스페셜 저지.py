import sys
from collections import deque

n = int(sys.stdin.readline())

graph = [[] for _ in range(n + 1)]
visited = [False] * (n + 1)

for _ in range(n - 1):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

check = deque(map(int, sys.stdin.readline().split()))

def dfs(queue):
    v = queue.popleft()

    if not queue:
        print(1)
        exit()
    visited[v] = True
    for i in range(len(graph[v])):
        if queue[0] in graph[v] and not visited[queue[0]]:
            dfs(queue)
    return False

if check[0] != 1:
    print(0)
    exit()

if not dfs(check):
    print(0)
