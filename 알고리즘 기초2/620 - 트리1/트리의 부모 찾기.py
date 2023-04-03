import sys

n = int(sys.stdin.readline())

graph = [[] for _ in range(n - 1)]

for _ in range(n - 1):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)


