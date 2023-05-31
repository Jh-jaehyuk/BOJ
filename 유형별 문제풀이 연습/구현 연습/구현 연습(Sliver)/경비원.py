import sys
from collections import deque


m, n = map(int, sys.stdin.readline().split())
a = int(sys.stdin.readline())
arr = [[-1] * (m + 1) for _ in range(n + 1)]
for i in range(n + 1):
    for j in range(m + 1):
        if i == 0 or i == n or j == 0 or j == m:
            arr[i][j] = 0

i = 1

for _ in range(a):
    direction, rocation = map(int, sys.stdin.readline().split())

    if direction == 1:
        arr[0][rocation] = i

    elif direction == 2:
        arr[n][rocation] = i

    elif direction == 3:
        arr[rocation][0] = i

    elif direction == 4:
        arr[rocation][m] = i

    i += 1

start_d, start_r = map(int, sys.stdin.readline().split())
if start_d == 1:
    start_x, start_y = 0, start_r

elif start_d == 2:
    start_x, start_y = n, start_r

elif start_d == 3:
    start_x, start_y = start_r, 0

elif start_d == 4:
    start_x, start_y = start_r, m

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs(v):
    while queue:
        x, y = queue.popleft()
        if arr[x][y] == v:
            return visited[x][y]

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if nx < 0 or nx > n or ny < 0 or ny > m or arr[nx][ny] == -1:
                continue

            if visited[nx][ny] == -1:
                visited[nx][ny] = visited[x][y] + 1
                queue.append([nx, ny])


answer = 0
for i in range(a + 1):
    visited = [[-1] * (m + 1) for _ in range(n + 1)]
    queue = deque()
    queue.append([start_x, start_y])
    visited[start_x][start_y] = 0
    k = bfs(i)
    answer += k

print(answer)
