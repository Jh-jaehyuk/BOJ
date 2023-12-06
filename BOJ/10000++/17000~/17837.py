import sys

n, k = map(int, sys.stdin.readline().split())

board = [[2] * (n + 2)]
for _ in range(n):
    board.append([2] + list(map(int, sys.stdin.readline().split())) + [2])
board.append([2] * (n + 2))

status = [[0, 0, 0] for _ in range(k + 1)]
checkers = [[[] for _ in range(n + 1)] for _ in range(n + 1)]

dx = [0, 0, 0, -1, 1]
dy = [0, 1, -1, 0, 0]

for i in range(1, k + 1):
    x, y, d = map(int, sys.stdin.readline().split())
    checkers[x][y].append(i)
    status[i] = [x, y, d]


def change_direction(dir):
    if dir == 1:
        return 2
    elif dir == 2:
        return 1
    elif dir == 3:
        return 4
    else:
        return 3


def move(x, y, idx, dir):
    checker_to_move = []

    while checkers[x][y][-1] != idx:
        checker_to_move.append(checkers[x][y].pop())
    checker_to_move.append(checkers[x][y].pop())

    nx, ny = x + dx[dir], y + dy[dir]

    if board[nx][ny] == 0:
        checkers[nx][ny].extend(reversed(checker_to_move))

        for checker in checker_to_move:
            status[checker][0] = nx
            status[checker][1] = ny

    elif board[nx][ny] == 1:
        checkers[nx][ny].extend(checker_to_move)

        for checker in checker_to_move:
            status[checker][0] = nx
            status[checker][1] = ny

    else:
        dir = change_direction(dir)
        nnx, nny = x + dx[dir], y + dy[dir]

        if board[nnx][nny] == 0:
            checkers[nnx][nny].extend(reversed(checker_to_move))

            for checker in checker_to_move:
                status[checker][0] = nnx
                status[checker][1] = nny

        elif board[nnx][nny] == 1:
            checkers[nnx][nny].extend(checker_to_move)

            for checker in checker_to_move:
                status[checker][0] = nnx
                status[checker][1] = nny

        else:
            checkers[x][y].extend(reversed(checker_to_move))

        status[idx][2] = dir


def check():
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if len(checkers[i][j]) >= 4:
                return True
    return False


result = 0
while True:
    flag = False
    if result >= 1000:
        break

    for i in range(1, k + 1):
        x, y, d = status[i]
        move(x, y, i, d)

        if check():
            flag = True
            break

    result += 1

    if flag:
        break

print(-1 if result >= 1000 else result)
