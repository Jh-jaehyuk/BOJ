import sys
from collections import deque

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

graph = [[] for _ in range(n + 1)]
indegree = [0] * (n + 1)
check = [True] * (n + 1)
count = [0] * (n + 1)

for _ in range(m):
    x, y, k = map(int, sys.stdin.readline().split())
    indegree[y] += 1
    graph[x].append((y, k))
    check[x] = False

queue = deque()
queue.append(n)
count[n] = 1

while queue:
    now = queue.popleft()

    for i, c in graph[now]:
        count[i] += c * count[now]
        indegree[i] -= 1

        if indegree[i] == 0:
            queue.append(i)

for i in range(1, n + 1):
    if check[i]:
        print(i, count[i])