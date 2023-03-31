import sys

n, m = map(int, sys.stdin.readline().split())
board = [list(map(int, sys.stdin.readline().rstrip())) for _ in range(n)]
max_sum = 0

def bitmask():
    global max_sum

    for i in range(1 << n * m):
        total = 0
        for row in range(n):
            row_sum = 0
            for col in range(m):
                idx = row * m + col
                if i & (1 << idx) != 0:
                    row_sum = row_sum * 10 + board[row][col]
                else:
                    total += row_sum
                    row_sum = 0
            total += row_sum

        for col in range(m):
            col_sum = 0
            for row in range(n):
                idx = row * m + col
                if i & (1 << idx) == 0:
                    col_sum = col_sum * 10 + board[row][col]
                else:
                    total += col_sum
                    col_sum = 0
            total += col_sum
        max_sum = max(max_sum, total)
    return

bitmask()
print(max_sum)
