import sys
sys.setrecursionlimit(10 ** 4)

dx = [1, 1, -1, -1, 1, -1, 0, 0]
dy = [0, 1, 0, 1, -1, -1, 1, -1]

def dfs(x, y):
    if x < 0 or x >= h or y < 0 or y >= w:
        return False

    if graph[x][y] == 1:
        graph[x][y] = 0

        for i in range(8):
            nx, ny = x + dx[i], y + dy[i]
            dfs(nx, ny)
        return True
    return False

while True:
    w, h = map(int, sys.stdin.readline().split())

    if w == 0 and h == 0:
        break

    graph = [list(map(int, sys.stdin.readline().split())) for _ in range(h)]
    result = 0

    for j in range(h):
        for k in range(w):
            if dfs(j, k) == True:
                result += 1

    print(result)
