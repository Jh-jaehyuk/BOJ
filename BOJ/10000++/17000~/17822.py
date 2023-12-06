import sys
from copy import deepcopy
from collections import deque

n, m, t = map(int, sys.stdin.readline().split())
board = [deque()]

for _ in range(n):
    board.append(deque(list(map(int, sys.stdin.readline().split()))))


def check():
    flag = False
    _board = deepcopy(board)

    for i in range(1, n + 1):
        for j in range(m):
            if board[i][j] == 0:
                continue

            if board[i][j] == board[i][(j + 1) % m]:
                _board[i][j] = 0
                _board[i][(j + 1) % m] = 0
                flag = True

            if board[i][j] == board[i][(j - 1) % m]:
                _board[i][j] = 0
                _board[i][(j - 1) % m] = 0
                flag = True

            if i == n:
                continue

            if board[i][j] == board[i + 1][j]:
                _board[i][j] = 0
                _board[i + 1][j] = 0
                flag = True

    if flag:
        return _board

    else:
        count = 0
        s = 0

        for i in range(1, n + 1):
            for j in range(m):
                if _board[i][j] == 0:
                    continue
                count += 1
                s += _board[i][j]

        if count == 0:
            return _board

        avg = s / count

        for i in range(1, n + 1):
            for j in range(m):
                if _board[i][j] == 0:
                    continue

                if _board[i][j] > avg:
                    _board[i][j] -= 1

                elif _board[i][j] < avg:
                    _board[i][j] += 1

        return _board


for _ in range(t):
    x, d, k = map(int, sys.stdin.readline().split())

    for i in range(x, n + 1, x):
        if d == 0:
            board[i].rotate(k)
        else:
            board[i].rotate(-k)

    board = check()

result = 0
for i in range(1, n + 1):
    for j in range(m):
        result += board[i][j]

print(result)
