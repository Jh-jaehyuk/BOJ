import sys
sys.setrecursionlimit(10**5)
N, R, Q = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(N + 1)]
visited = [0] * (N + 1)

for _ in range(N - 1):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)


def dfs(node, visited):
    visited[node] += 1
    for i in graph[node]:
        if not visited[i]:
            visited[node] += dfs(i, visited)
    return visited[node]


dfs(R, visited)
for _ in range(Q):
    x = int(sys.stdin.readline())
    print(visited[x])
