import sys
sys.setrecursionlimit(10 ** 5)

T = int(sys.stdin.readline())
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def dfs(x, y, visited):
    visited[x][y] = True

    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]

        if 0 <= nx < n and 0 <= ny < m and board[nx][ny] == 1 and not visited[nx][ny]:
            dfs(nx, ny, visited)


for _ in range(T):
    m, n, k = map(int, sys.stdin.readline().split())
    board = [[0] * m for _ in range(n)]
    visited = [[False] * m for _ in range(n)]
    count = 0

    for _ in range(k):
        y, x = map(int, sys.stdin.readline().split())
        board[x][y] = 1

    for i in range(n):
        for j in range(m):
            if board[i][j] == 1 and not visited[i][j]:
                dfs(i, j, visited)
                count += 1

    print(count)
