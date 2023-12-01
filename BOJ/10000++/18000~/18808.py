import sys
from collections import defaultdict

n, m, k = map(int, sys.stdin.readline().split())
stickers = defaultdict(list)
stickers_sizes = []
board = [[0] * m for _ in range(n)]

for idx in range(k):
    r, c = map(int, sys.stdin.readline().split())
    stickers_sizes.append([r, c])

    for _ in range(r):
        stickers[idx].append(list(map(int, sys.stdin.readline().split())))


def rotate90(arr):
    row, col = len(arr), len(arr[0])
    tmp = [[0] * row for _ in range(col)]

    for i in range(row):
        for j in range(col):
            tmp[j - col][row - i - 1] = arr[i][j]

    return tmp


def check(board, sticker, size, x, y):
    row, col = size

    if row > n or col > m:
        return False

    for i in range(row):
        for j in range(col):
            if board[x + i][y + j] and sticker[i][j]:
                return False

    return True


def attach(board, sticker, size):
    row, col = size

    for i in range(n - row + 1):
        for j in range(m - col + 1):
            if check(board, sticker, size, i, j):
                for r in range(row):
                    for c in range(col):
                        if not sticker[r][c]:
                            continue
                        board[i + r][j + c] = sticker[r][c]
                return True
    return False


for idx in range(k):
    st = stickers[idx]
    for cycle in range(4):
        if cycle > 0:
            st = rotate90(st)

        if cycle % 2 == 1:
            size = stickers_sizes[idx][::-1]
        else:
            size = stickers_sizes[idx]

        if attach(board, st, size):
            break


result = 0
for i in range(n):
    for j in range(m):
        result += board[i][j]

print(result)