import sys
sys.setrecursionlimit(10 ** 4)

n, m = map(int, sys.stdin.readline().split())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def dfs(x, y):
    visited[x][y] = True

    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]

        if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny] and board[nx][ny] != 0:
            dfs(nx, ny)


def melt(x, y):
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]

        if 0 <= nx < n and 0 <= ny < m and board[nx][ny] != 0:
            board[nx][ny] -= 1
            check[nx][ny] = True


result = 0

while True:
    result += 1
    count = 0
    check = [[False] * m for _ in range(n)]
    visited = [[False] * m for _ in range(n)]

    for i in range(n):
        for j in range(m):
            if board[i][j] == 0 and not check[i][j]:
                melt(i, j)

    for i in range(n):
        for j in range(m):
            if board[i][j] != 0 and not visited[i][j]:
                count += 1
                dfs(i, j)

    if count > 1:
        break

    elif count == 0:
        print(0)
        quit(0)

print(result)
