import sys

n = int(sys.stdin.readline())

graph = [list(map(int, sys.stdin.readline().rstrip())) for _ in range(n)]

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

def dfs(x, y):
    global count

    if x < 0 or x >= n or y < 0 or y >= n:
        return False

    if graph[x][y] == 1:
        count += 1
        graph[x][y] = 0
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            dfs(nx, ny)
        return True
    return False

answer = []
count = 0
result = 0

for j in range(n):
    for k in range(n):
        if dfs(j, k) == True:
            answer.append(count)
            result += 1
            count = 0

answer.sort()

print(result)
for x in answer:
    print(x)
