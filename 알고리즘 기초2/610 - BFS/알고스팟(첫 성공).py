import sys
from collections import deque

m, n = map(int, sys.stdin.readline().split())

board = [list(map(int, sys.stdin.readline().rstrip())) for _ in range(n)]
visited = [[False] * m for _ in range(n)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(x, y):
    queue = deque()
    queue.append((x, y))

    visited[x][y] = True

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if nx < 0 or nx >= n or ny < 0 or ny >= m or visited[nx][ny]:
                continue

            if board[nx][ny] == 0:
                board[nx][ny] = board[x][y]
                queue.appendleft((nx, ny))
                visited[nx][ny] = True

            else:
                board[nx][ny] = board[x][y] + 1
                queue.append((nx, ny))
                visited[nx][ny] = True

    return board[n - 1][m - 1]

print(bfs(0, 0))
