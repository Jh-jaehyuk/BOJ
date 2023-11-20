import sys
sys.setrecursionlimit(10 ** 6)

n = int(sys.stdin.readline())
graph = [[] for _ in range(n + 1)]

for _ in range(n - 1):
    u, v = map(int, sys.stdin.readline().split())
    graph[u].append(v)
    graph[v].append(u)

visited = [False] * (n + 1)
dp = [[0, 0] for _ in range(n + 1)]


def DFS(node):
    visited[node] = True
    dp[node][0] = 1

    for i in graph[node]:
        if visited[i]:
            continue
        DFS(i)
        dp[node][0] += min(dp[i][0], dp[i][1])
        dp[node][1] += dp[i][0]


DFS(1)
print(min(dp[1]))
