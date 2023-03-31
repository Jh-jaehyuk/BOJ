import sys

n, m = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(n)]
visited = [False] * 2001

for i in range(m):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

# dfs 에서 depth 가 5이면 정답.
def dfs(idx, depth):
    if depth == 4:
        print(1)
        exit()

    for j in graph[idx]:
        if not visited[j]:
            visited[j] = True
            dfs(j, depth + 1)
            visited[j] = False

for k in range(n):
    visited[k] = True
    dfs(k, 0)
    visited[k] = False

print(0)
