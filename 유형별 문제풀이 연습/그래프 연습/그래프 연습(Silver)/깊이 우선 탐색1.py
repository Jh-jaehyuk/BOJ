import sys
sys.setrecursionlimit(10**5)
N, M, R = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(N + 1)]
visited = [False] * (N + 1)
result = [0] * (N + 1)
depth = 1

for _ in range(M):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(len(graph)):
    graph[i] = sorted(graph[i])


def dfs(start, visited):
    global depth
    depth += 1
    visited[start] = True
    for i in graph[start]:
        if not visited[i]:
            result[i] = depth
            dfs(i, visited)


result[R] = 1
dfs(R, visited)
for i in range(1, len(result)):
    print(result[i])
