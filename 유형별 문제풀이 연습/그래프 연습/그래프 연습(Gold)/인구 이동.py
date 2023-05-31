import sys
from collections import deque

N, L, R = map(int, sys.stdin.readline().split())
A = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
count = 0


def check(x, y):
    global flag
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < N and 0 <= ny < N:
            if L <= abs(A[x][y] - A[nx][ny]) <= R:
                flag = False
                return


flag = True
for i in range(N):
    for j in range(N):
        check(i, j)

while not flag:
    count += 1
    visited = [[False] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if not visited[i][j]:
                visited[i][j] = True
                queue = deque()
                queue.append((i, j))
                tmp = [(A[i][j], i, j)]

                while queue:
                    x, y = queue.popleft()

                    for k in range(4):
                        nx, ny = x + dx[k], y + dy[k]

                        if 0 <= nx < N and 0 <= ny < N and L <= abs(A[x][y] - A[nx][ny]) <= R and not visited[nx][ny]:
                            tmp.append((A[nx][ny], nx, ny))
                            visited[nx][ny] = True
                            queue.append((nx, ny))

                if len(tmp) > 1:
                    s = 0
                    for x in tmp:
                        s += x[0]
                    s //= len(tmp)
                    while tmp:
                        a, b, c = tmp.pop()
                        A[b][c] = s

    flag = True
    for i in range(N):
        for j in range(N):
            check(i, j)

    if flag:
        break

print(count)
