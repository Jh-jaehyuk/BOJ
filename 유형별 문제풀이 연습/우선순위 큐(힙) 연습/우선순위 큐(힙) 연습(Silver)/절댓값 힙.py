import sys
import heapq

n = int(sys.stdin.readline())
pos = []
neg = []

for _ in range(n):
    x = int(sys.stdin.readline())

    if x > 0:
        heapq.heappush(pos, x)
    elif x < 0:
        heapq.heappush(neg, -x)
    else:
        if pos and neg:
            a = heapq.heappop(pos)
            b = heapq.heappop(neg)
            if a >= b:
                print(-b)
                heapq.heappush(pos, a)
            else:
                print(a)
                heapq.heappush(neg, b)

        elif pos and not neg:
            print(heapq.heappop(pos))

        elif not pos and neg:
            print(-heapq.heappop(neg))

        else:
            print(0)
