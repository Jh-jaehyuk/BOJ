import sys
from collections import deque


n, m, r = map(int, sys.stdin.readline().split())

arr = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
answer = [[0] * m for _ in range(n)]

x = min(n, m) // 2
queue = deque()

for i in range(x):
    queue.clear()
    queue.extend(arr[i][i:(m - i)])
    queue.extend([row[m - i - 1] for row in arr[(i + 1):(n - i - 1)]])
    queue.extend(arr[n - i - 1][i:(m - i)][::-1])
    queue.extend([row[i] for row in arr[(i + 1):(n - i - 1)][::-1]])

    queue.rotate(-1 * r)

    for j in range(i, m - i):
        answer[i][j] = queue.popleft()

    for j in range(i + 1, n - i - 1):
        answer[j][m - i - 1] = queue.popleft()

    for j in range(m - i - 1, i - 1, -1):
        answer[n - i - 1][j] = queue.popleft()

    for j in range(n - i - 2, i, -1):
        answer[j][i] = queue.popleft()

for line in answer:
    print(*line)
