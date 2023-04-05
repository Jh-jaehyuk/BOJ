import sys
from collections import deque

sys.setrecursionlimit(10 ** 5)

n = int(sys.stdin.readline())
graph = [[] for _ in range(n + 1)]
visited = [False] * (n + 1)

for _ in range(n):
    tmp = list(map(int, sys.stdin.readline().split()))
    i = 1
    while i < len(tmp) - 1:
        graph[tmp[0]].append([tmp[i], tmp[i + 1]])
        i += 2


def bfs(x):
    queue = deque()
    queue.append([x, 0])
    max_d = 0
    max_idx = x
    visited[x] = True

    while queue:
        idx, d = queue.popleft()

        if max_d < d:
            max_d = d
            max_idx = idx

        for a, b in graph[idx]:
            if not visited[a]:
                queue.append([a, d + b])
                visited[a] = True

    return max_idx, max_d


idx1, d1 = bfs(1)
visited = [False] * (n + 1)
idx2, d2 = bfs(idx1)
print(d2)

# 참고 : https://kyun2da.github.io/2021/05/04/tree's_diameter/
