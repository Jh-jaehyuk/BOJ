import sys
from collections import deque

n = int(sys.stdin.readline())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
arr.sort(key=lambda x: (x[1], x[0]))

queue = deque(arr)
stack = []
count = 0

while queue:
    start, end = queue.popleft()
    if not stack:
        stack.append([start, end])
        count += 1
        continue

    if stack[-1][1] <= start:
        stack.pop()
        stack.append([start, end])
        count += 1

print(count)
