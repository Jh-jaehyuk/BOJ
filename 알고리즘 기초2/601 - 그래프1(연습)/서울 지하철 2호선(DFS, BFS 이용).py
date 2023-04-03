# DFS로 사이클인지 아닌지 판별
# BFS로 순환선까지의 거리를 판별함.
# DFS와 BFS 개념이 모두 쓰이는 문제!
import sys
from collections import deque
sys.setrecursionlimit(10**4)

n = int(sys.stdin.readline())
graph = [[] for _ in range(n + 1)]
is_cycle = [False] * (n + 1)
d = [-1] * (n + 1)

for _ in range(n):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

def dfs(start, now, count):
    global cycle

    visited[now] = True
    if start == now and count >= 2:
        cycle = True
        return

    for j in graph[now]:
        if not visited[j]:
            dfs(start, j, count + 1)

        elif j == start and count >= 2:
            dfs(start, j, count)
    return

def check():
    queue = deque()

    for i in range(1, n + 1):
        if is_cycle[i]:
            d[i] = 0
            queue.append(i)

    while queue:
        now = queue.popleft()
        for j in graph[now]:
            if d[j] == -1:
                queue.append(j)
                d[j] = d[now] + 1

    print(*d[1:])

for i in range(1, n + 1):
    visited = [False] * (n + 1)
    cycle = False
    dfs(i, i, 0)
    if cycle:
        is_cycle[i] = True

check()
