import sys
sys.setrecursionlimit(10 ** 5)

n = int(sys.stdin.readline())

graph = [[] for _ in range(n + 1)]
parent = [0] * (n + 1)

for _ in range(n - 1):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

def dfs(x):
    for i in graph[x]:
        if parent[i] == 0:
            parent[i] = x
            dfs(i)

dfs(1)
for j in range(2, n + 1):
    print(parent[j])
