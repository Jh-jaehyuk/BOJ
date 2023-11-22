import sys
from collections import deque

n = int(sys.stdin.readline())

graph = [[] for _ in range(n + 1)]
indegree = [0] * (n + 1)
build = [0] * (n + 1)
time = [0] * (n + 1)

for i in range(1, n + 1):
    tmp = list(map(int, sys.stdin.readline().split()))
    build[i] = tmp[0]

    if tmp[1] == 0:
        continue

    indegree[i] += tmp[1]
    for node in tmp[2:]:
        graph[node].append(i)

queue = deque()

for i in range(1, n + 1):
    if indegree[i] == 0:
        queue.append(i)
        time[i] = build[i]

result = 0
while queue:
    now = queue.popleft()
    result = max(result, time[now])

    for node in graph[now]:
        time[node] = max(time[node], time[now] + build[node])
        indegree[node] -= 1

        if indegree[node] == 0:
            queue.append(node)

print(result)