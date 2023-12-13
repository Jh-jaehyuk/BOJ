import sys
import heapq

n, k = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
queue = []

if max(arr) > (n + 1) // 2:
    print(-1)
    exit(0)

for color, count in enumerate(arr, start=1):
    heapq.heappush(queue, [-count, color])

result = []
prev = None

while queue:
    count, color = heapq.heappop(queue)
    count *= -1

    if prev is not None:
        heapq.heappush(queue, prev)

    count -= 1
    result.append(color)

    if count == 0:
        prev = None

    else:
        prev = [-count, color]

print(*result)