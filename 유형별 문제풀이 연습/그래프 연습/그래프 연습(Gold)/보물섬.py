import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
board = [list(sys.stdin.readline().strip()) for _ in range(n)]
visited = [[-1] * m for _ in range(n)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs(x, y):
    queue.append((x, y))
    visited[x][y] = 0

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if 0 <= nx < n and 0 <= ny < m and board[nx][ny] == 'L':
                if visited[nx][ny] == -1:
                    visited[nx][ny] = visited[x][y] + 1
                    queue.append((nx, ny))


queue = deque()
answer = 0

for i in range(n):
    for j in range(m):
        if board[i][j] == 'L':
            visited = [[-1] * m for _ in range(n)]
            bfs(i, j)
            val = max([max(x) for x in visited])
            if answer < val:
                answer = val

print(answer)
