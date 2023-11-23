import sys
import heapq

T = int(sys.stdin.readline())


def solve():
    k = int(sys.stdin.readline())
    tmp = list(map(int, sys.stdin.readline().split()))
    queue = []

    for i in tmp:
        heapq.heappush(queue, i)

    result = 0
    while len(queue) > 1:
        x = heapq.heappop(queue)
        y = heapq.heappop(queue)
        result += (x + y)
        heapq.heappush(queue, x + y)

    print(result)


for t in range(T):
    solve()
