import sys
from copy import deepcopy

n, m, k = map(int, sys.stdin.readline().split())
board = [[[] for _ in range(n)] for _ in range(n)]

for _ in range(m):
    r, c, mass, speed, direction = map(int, sys.stdin.readline().split())
    board[r - 1][c - 1].append((mass, speed, direction))

dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]


def move():
    tmp = [[[] for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            while board[i][j]:
                mass, sp, dir = board[i][j].pop()
                nx = (i + (dx[dir] * sp)) % n
                ny = (j + (dy[dir] * sp)) % n
                tmp[nx][ny].append((mass, sp, dir))

    return tmp


def split():
    for i in range(n):
        for j in range(n):
            if len(board[i][j]) > 1:
                count = len(board[i][j])
                mass = 0
                speed = 0
                odd, even = 0, 0

                for ma, sp, di in board[i][j]:
                    mass += ma
                    speed += sp
                    if di % 2 == 0:
                        even += 1
                    else:
                        odd += 1

                board[i][j].clear()
                next_mass = mass // 5
                if next_mass == 0:
                    continue
                next_speed = speed // count

                if odd == count or even == count:
                    for next_dir in [0, 2, 4, 6]:
                        board[i][j].append((next_mass, next_speed, next_dir))
                else:
                    for next_dir in [1, 3, 5, 7]:
                        board[i][j].append((next_mass, next_speed, next_dir))


for _ in range(k):
    board = move()
    split()

result = 0
for i in range(n):
    for j in range(n):
        if not board[i][j]:
            continue

        for tmp in board[i][j]:
            result += tmp[0]

print(result)
