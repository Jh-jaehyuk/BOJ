import sys
from collections import deque

n, k = map(int, sys.stdin.readline().split())

queue = deque()
queue.append(n)

d = [0] * 100001
move = [0] * 100001

def solution(v):
    tmp = []
    x = v

    for _ in range(d[v] + 1):
        tmp.append(x)
        x = move[x]
    tmp.reverse()
    print(*tmp)

def bfs():
    queue = deque()
    queue.append(n)

    while queue:
        v = queue.popleft()

        if v == k:
            print(d[v])
            solution(v)
            return

        for i in [v + 1, v - 1, v * 2]:
            if 0 <= i <= 100000 and not d[i]:
                queue.append(i)
                d[i] = d[v] + 1
                move[i] = v

bfs()
