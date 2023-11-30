import sys
import heapq

n = int(sys.stdin.readline())
queue = []

for i in range(n):
    x = int(sys.stdin.readline())
    heapq.heappush(queue, (x, i))

board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
visited = [False] * n

result = 0
while queue:
    val, idx = heapq.heappop(queue)

    if visited[idx]:
        continue

    visited[idx] = True
    result += val
    for i in range(n):
        heapq.heappush(queue, (board[idx][i], i))

print(result)