import sys
from collections import deque

n = int(sys.stdin.readline())
graph = [[] for _ in range(n + 1)]
result = [int(1e9)] * (n + 1)
d = [-1] * (n + 1)

while True:
    a, b = map(int, sys.stdin.readline().split())

    if a == -1 and b == -1:
        break

    graph[a].append(b)
    graph[b].append(a)


def BFS(start):
    queue = deque()
    queue.append(start)
    d[start] = 0

    while queue:
        now = queue.popleft()

        for i in graph[now]:
            if d[i] != -1:
                continue
            d[i] = d[now] + 1
            queue.append(i)


for i in range(1, n + 1):
    d = [-1] * (n + 1)
    BFS(i)
    result[i] = max(d)

min_val = min(result)
count = result.count(min_val)
print(min_val, count)

for i in range(1, n + 1):
    if result[i] == min_val:
        print(i, end=" ")
