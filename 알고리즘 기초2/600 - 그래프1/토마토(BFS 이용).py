import sys
from collections import deque

m, n = map(int, sys.stdin.readline().split())

graph = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

queue = deque()
for j in range(n):
    for k in range(m):
        if graph[j][k] == 1:
            queue.append((j, k))

def bfs():
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if 0 <= nx < n and 0 <= ny < m and graph[nx][ny] == 0:
                graph[nx][ny] = graph[x][y] + 1
                queue.append((nx, ny))

bfs()

result = 0
for j in graph:
    for k in j:
        if k == 0:
            print(-1)
            exit()
    result = max(result, max(j))

print(result - 1)
