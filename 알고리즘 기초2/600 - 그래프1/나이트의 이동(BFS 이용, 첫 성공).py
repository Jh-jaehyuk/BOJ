import sys
from collections import deque

T = int(sys.stdin.readline())
dx = [-2, -1, 1, 2, -2, -1, 1, 2]
dy = [-1, -2, -2, -1, 1, 2, 2, 1]

def bfs():
    while queue:
        x, y = queue.popleft()
        if x == a and y == b:
            print(visited[a][b])
            return

        for i in range(8):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < l and 0 <= ny < l and not visited[nx][ny]:
                queue.append((nx, ny))
                visited[nx][ny] = visited[x][y] + 1

for _ in range(T):
    l = int(sys.stdin.readline())
    visited = [[0] * l for _ in range(l)]
    board = [list(i for i in range(l)) for _ in range(l)]
    start_x, start_y = map(int, sys.stdin.readline().split())
    a, b = map(int, sys.stdin.readline().split())

    queue = deque()
    queue.append((start_x, start_y))

    bfs()
