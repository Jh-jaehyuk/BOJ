import sys
from collections import deque

M, N, H = map(int, sys.stdin.readline().split())
box = [[list(map(int, sys.stdin.readline().split())) for _ in range(N)] for _ in range(H)]
dx = [-1, 1, 0, 0, 0, 0]
dy = [0, 0, -1, 1, 0, 0]
dz = [0, 0, 0, 0, -1, 1]


queue = deque()
for i in range(H):
    for j in range(N):
        for k in range(M):
            if box[i][j][k] == 1:
                queue.append((i, j, k))
tmp = []
count = 0
while queue:
    z, x, y = queue.popleft()

    for i in range(6):
        nx, ny, nz = x + dx[i], y + dy[i], z + dz[i]

        if 0 <= nx < N and 0 <= ny < M and 0 <= nz < H and box[nz][nx][ny] == 0:
            tmp.append((nz, nx, ny))
            box[nz][nx][ny] = 1

    if not queue and tmp:
        count += 1
        for i in tmp:
            queue.append(i)
        tmp = []

for i in range(H):
    for j in range(N):
        for k in range(M):
            if box[i][j][k] == 0:
                print(-1)
                quit(0)

print(count)
