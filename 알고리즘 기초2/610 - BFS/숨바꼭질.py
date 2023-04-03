import sys
from collections import deque

n, k = map(int, sys.stdin.readline().split())
board = [0] * 200000

queue = deque()
queue.append(n)

while queue:
    v = queue.popleft()

    if v == k:
        print(board[k])
        break

    for i in [v - 1, v + 1, v * 2]:
        if 0 <= i < 200000 and not board[i]:
            board[i] = board[v] + 1
            queue.append(i)
