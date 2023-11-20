import sys
sys.setrecursionlimit(10 ** 5)

n, m = map(int, sys.stdin.readline().split())
parent = [-1] + list(map(int, sys.stdin.readline().split()))
graph = [[] for _ in range(n + 1)]
visited = [False] * (n + 1)

for i in range(2, n + 1):
    graph[parent[i]].append(i)

award = [0] * (n + 1)

for _ in range(m):
    i, w = map(int, sys.stdin.readline().split())
    award[i] += w


def DFS(node):
    if visited[node]:
        return

    visited[node] = True

    for i in graph[node]:
        award[i] += award[node]
        DFS(i)


DFS(1)

for i in range(1, n + 1):
    print(award[i], end=' ')