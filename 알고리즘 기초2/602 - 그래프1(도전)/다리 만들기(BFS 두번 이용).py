import sys
from collections import deque

n = int(sys.stdin.readline())

graph = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
visited = [[False] * n for _ in range(n)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs(x, y):
    queue = deque()
    queue.append((x, y))

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if 0 <= nx < n and 0 <= ny < n and \
                not visited[nx][ny] and graph[nx][ny]:
                visited[nx][ny] = True
                graph[nx][ny] = a
                queue.append((nx, ny))

def get_distance(v):
    q = deque()
    d = [[-1] * n for _ in range(n)]

    for i in range(n):
        for j in range(n):
            if graph[i][j] == v:
                d[i][j] = 0
                q.append((i, j))

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if 0 <= nx < n and 0 <= ny < n:
                if graph[nx][ny] and graph[nx][ny] != v:
                    return d[x][y]

                elif not graph[nx][ny] and d[nx][ny] == -1:
                    d[nx][ny] = d[x][y] + 1
                    q.append((nx, ny))

    return int(1e9)

a = 1
min_d = int(1e9)

for i in range(n):
    for j in range(n):
        if graph[i][j] and not visited[i][j]:
            visited[i][j] = True
            graph[i][j] = a
            bfs(i, j)
            a += 1

for k in range(1, a):
    min_d = min(min_d, get_distance(k))
print(min_d)
