import sys

sys.setrecursionlimit(10 ** 5)

n = int(sys.stdin.readline())
graph = [[] for _ in range(n + 1)]
visited = [False] * (n + 1)

end = 1
max_w = 0

for _ in range(n - 1):
    parent, child, weight = map(int, sys.stdin.readline().split())
    graph[parent].append([child, weight])
    graph[child].append([parent, weight])


def dfs(start, weight):
    global max_w, end
    if visited[start]:
        return

    visited[start] = True

    if max_w < weight:
        end = start
        max_w = weight

    for i in range(len(graph[start])):
        dfs(graph[start][i][0], weight + graph[start][i][1])


dfs(end, 0)
max_w = 0
visited = [False] * (n + 1)

dfs(end, 0)
print(max_w)
