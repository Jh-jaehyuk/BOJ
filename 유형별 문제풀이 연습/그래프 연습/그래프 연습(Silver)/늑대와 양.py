import sys
from collections import deque

r, c = map(int, sys.stdin.readline().split())
board = [list(sys.stdin.readline().rstrip()) for _ in range(r)]
wolf = []
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for i in range(len(board)):
    for j in range(len(board[i])):
        if board[i][j] == '.':
            board[i][j] = 'D'
        elif board[i][j] == 'W':
            wolf.append((i, j))

queue = deque(wolf)

while queue:
    x, y = queue.popleft()

    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]

        if 0 <= nx < r and 0 <= ny < c and board[nx][ny] == 'S':
            print(0)
            quit(0)

print(1)
for i in board:
    print(*i, sep='')
