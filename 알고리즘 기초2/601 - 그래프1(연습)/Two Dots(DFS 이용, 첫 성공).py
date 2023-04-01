import sys

n, m = map(int, sys.stdin.readline().split())
board = [list(sys.stdin.readline().rstrip()) for _ in range(n)]
visited = [[False] * m for _ in range(n)]

dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]
cycle = False

def dfs(x, y, count):
    global cycle

    visited[x][y] = True

    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]

        if count >= 4 and nx == start_x and ny == start_y:
            cycle = True

        if 0 <= nx < n and 0 <= ny < m and\
                not visited[nx][ny] and board[x][y] == board[nx][ny]:
            visited[nx][ny] = True
            dfs(nx, ny, count + 1)
            visited[nx][ny] = False

for j in range(n):
    for k in range(m):
        start_x, start_y = j, k
        dfs(j, k, 1)
        if cycle:
            print('Yes')
            exit()
print('No')
