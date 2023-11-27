import sys
from collections import deque
from itertools import combinations

n, m, g, r = map(int, sys.stdin.readline().split())
board = [[*map(int, sys.stdin.readline().split())] for _ in range(n)]
arr = []
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for i in range(n):
    for j in range(m):
        if board[i][j] == 2:
            arr.append((i, j))


def bfs(combi, cb):
    queue = deque()
    tmp = 0
    visited = [[[0, 0] for _ in range(m)] for _ in range(n)]

    for x, y in cb:
        visited[x][y][1] = 1
        queue.append((x, y))

    for x, y in combi:
        if visited[x][y][1] == 1:
            continue
        visited[x][y][1] = 2
        queue.append((x, y))

    while queue:
        x, y = queue.popleft()
        t = visited[x][y][0]
        c = visited[x][y][1]

        if visited[x][y][1] == 3:
            continue

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue

            if board[nx][ny] == 0:
                continue

            if visited[nx][ny][1] == 0:
                visited[nx][ny] = [t + 1, c]
                queue.append((nx, ny))

            elif visited[nx][ny][1] == 1:
                if c == 2 and visited[nx][ny][0] == t + 1:
                    tmp += 1
                    visited[nx][ny][1] = 3

            elif visited[nx][ny][1] == 2:
                if c == 1 and visited[nx][ny][0] == t + 1:
                    tmp += 1
                    visited[nx][ny][1] = 3

    return tmp


result = -1
for combi in combinations(arr, g + r):
    for cb in combinations(combi, g):
        result = max(result, bfs(combi, cb))

print(result)
