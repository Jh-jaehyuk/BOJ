import sys
sys.setrecursionlimit(10 ** 5)

m, n = map(int, sys.stdin.readline().split())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(m)]
visited = [[False] * n for _ in range(m)]
dx = [-1, -1, -1, 0, 0, 1, 1, 1]
dy = [-1, 0, 1, -1, 1, -1, 0, 1]


def dfs(x, y, visited):
    visited[x][y] = True

    for i in range(8):
        nx, ny = x + dx[i], y + dy[i]

        if 0 <= nx < m and 0 <= ny < n and not visited[nx][ny] and board[nx][ny] == 1:
            dfs(nx, ny, visited)


count = 0
for i in range(m):
    for j in range(n):
        if board[i][j] == 1 and not visited[i][j]:
            dfs(i, j, visited)
            count += 1
print(count)
