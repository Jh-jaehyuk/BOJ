import sys
from collections import deque

n, k = map(int, sys.stdin.readline().split())
d = [0] * 100001

queue = deque()
queue.append(n)
d[n] = 1

while queue:
    v = queue.popleft()

    if v == k:
        print(d[k] - 1)
        break

    for i in [v * 2, v + 1, v - 1]:
        if 0 <= i <= 100000 and not d[i]:
            if i == v * 2:
                d[i] = d[v]
                queue.appendleft(i)
            else:
                d[i] = d[v] + 1
                queue.append(i)
