import sys

n, m, b = map(int, sys.stdin.readline().split())
board = []
for _ in range(n):
    board.extend(list(map(int, sys.stdin.readline().split())))
min_val, max_val = min(board), max(board)
min_t = int(1e9)
max_h = 0

for i in range(min_val, max_val + 1):
    tmp_t = 0
    tmp_b = b
    for j in range(n * m):
        if board[j] > i:
            tmp_t += (board[j] - i) * 2
            tmp_b += (board[j] - i)
        else:
            tmp_t += (i - board[j])
            tmp_b -= (i - board[j])

    if tmp_b >= 0:
        if tmp_t <= min_t:
            min_t = tmp_t
            max_h = i

print(min_t, max_h)
