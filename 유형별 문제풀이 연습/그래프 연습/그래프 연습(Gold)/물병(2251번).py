from collections import deque


def move(x, y):
    if not visited[x][y]:
        visited[x][y] = True
        queue.append((x, y))


def bfs():
    while queue:
        x, y = queue.popleft()
        z = c - x - y
        # a 물병이 비었다면 result에 추가
        if x == 0:
            result.append(z)
        # a -> b
        tmp = min(x, b - y)
        move(x - tmp, y + tmp)
        # a -> c
        tmp = min(x, c - z)
        move(x - tmp, y)
        # b -> a
        tmp = min(y, a - x)
        move(x + tmp, y - tmp)
        # b -> c
        tmp = min(y, c - z)
        move(x, y - tmp)
        # c -> a
        tmp = min(z, a - x)
        move(x + tmp, y)
        # c -> b
        tmp = min(z, b - y)
        move(x, y + tmp)


a, b, c = map(int, input().split())

queue = deque()
queue.append((0, 0))

visited = [[False] * (b + 1) for _ in range(a + 1)]
visited[0][0] = True

result = []

bfs()
result.sort()

print(*result)
