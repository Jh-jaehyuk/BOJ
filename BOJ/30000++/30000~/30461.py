import sys
import copy

n, m, q = map(int, sys.stdin.readline().rstrip().split())
board = []

for i in range(n):
    board.append(list(map(int, sys.stdin.readline().rstrip().split())))

prefix_sum = copy.deepcopy(board)

for j in range(m):
    for i in range(1, n):
        prefix_sum[i][j] += prefix_sum[i - 1][j]

for i in range(1, n):
    for j in range(1, m):
        prefix_sum[i][j] += prefix_sum[i - 1][j - 1]

for _ in range(q):
    x, y = map(int, sys.stdin.readline().split())
    print(prefix_sum[x - 1][y - 1])