import sys
from collections import deque

r, c = map(int, sys.stdin.readline().split())

board = [list(sys.stdin.readline().rstrip()) for _ in range(r)]
visited_j = [[0] * c for _ in range(r)]
visited_f = [[0] * c for _ in range(r)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
start_x, start_y = 0, 0
f = deque()
for i in range(r):
    for j in range(c):
        if board[i][j] == 'F':
            visited_f[i][j] = 1
            f.append((i, j))
        elif board[i][j] == 'J':
            visited_j[i][j] = 1
            start_x, start_y = i, j

queue = deque()
queue.append((start_x, start_y))


def bfs():
    while f:
        x, y = f.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if 0 <= nx < r and 0 <= ny < c and board[nx][ny] != '#' and not visited_f[nx][ny]:
                visited_f[nx][ny] = visited_f[x][y] + 1
                f.append((nx, ny))

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if 0 <= nx < r and 0 <= ny < c:
                if board[nx][ny] != '#' and not visited_j[nx][ny]:
                    if not visited_f[nx][ny] or visited_f[nx][ny] > visited_j[x][y] + 1:
                        visited_j[nx][ny] = visited_j[x][y] + 1
                        queue.append((nx, ny))
            else:
                return visited_j[x][y]

    return 'IMPOSSIBLE'


print(bfs())
