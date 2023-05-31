import sys

r, c = map(int, sys.stdin.readline().split())
board = [list(sys.stdin.readline().rstrip()) for _ in range(r)]
visited = [[False] * c for _ in range(r)]
alpha_check = [False] * 26
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def dfs(x, y, count):
    global max_val
    max_val = max(max_val, count)
    alpha_check[ord(board[x][y]) - ord('A')] = True
    visited[x][y] = True
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]

        if 0 <= nx < r and 0 <= ny < c and not visited[nx][ny] and not alpha_check[ord(board[nx][ny]) - ord('A')]:
            dfs(nx, ny, count + 1)
            alpha_check[ord(board[nx][ny]) - ord('A')] = False
            visited[nx][ny] = False


max_val = 0
dfs(0, 0, 1)
print(max_val)
