import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())

heavy = [[] for _ in range(n + 1)]
light = [[] for _ in range(n + 1)]
mid = (n + 1) // 2

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    heavy[b].append(a)
    light[a].append(b)


def bfs(start, arr):
    count = 0

    queue = deque()
    queue.append(start)

    while queue:
        v = queue.popleft()
        for i in arr[v]:
            if not visited[i]:
                count += 1
                visited[i] = True
                queue.append(i)

    return count


answer = 0

for i in range(1, n + 1):
    visited = [False] * (n + 1)
    visited[i] = True
    if bfs(i, heavy) >= mid:
        answer += 1
    if bfs(i, light) >= mid:
        answer += 1

print(answer)
