import sys
from collections import defaultdict
sys.setrecursionlimit(10 ** 5)

n, m, k = map(int, sys.stdin.readline().split())
board = [list(sys.stdin.readline().rstrip()) for _ in range(n)]
check = set()
check_list = list()
d = defaultdict(int)

dx = [-1, -1, -1, 0, 0, 1, 1, 1]
dy = [-1, 0, 1, -1, 1, -1, 0, 1]

for _ in range(k):
    x = sys.stdin.readline().rstrip()
    check.add(x)
    check_list.append(x)


def DFS(x, y, s):
    if len(s) > 5:
        return

    if s in check:
        d[s] += 1

    for i in range(8):
        nx, ny = x + dx[i], y + dy[i]
        nx %= n
        ny %= m

        DFS(nx, ny, s + board[nx][ny])


for i in range(n):
    for j in range(m):
        DFS(i, j, board[i][j])

for i in check_list:
    print(d[i])
