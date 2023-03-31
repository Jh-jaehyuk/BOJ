import sys

sys.setrecursionlimit(10 ** 6)
k = int(sys.stdin.readline())

def dfs(x, group):
    visited[x] = group

    for i in graph[x]:
        if not visited[i]:
            if not dfs(i, -group):
                return False
        elif visited[i] == group:
            return False
    return True

for _ in range(k):
    v, e = map(int, sys.stdin.readline().split())
    graph = [[] for _ in range(v + 1)]
    visited = [0] * (v + 1)

    for _ in range(e):
        a, b = map(int, sys.stdin.readline().split())
        graph[a].append(b)
        graph[b].append(a)

    answer = True

    for i in range(1, v + 1):
        if visited[i]:
            continue

        if not answer:
            break

        answer = dfs(i, 1)

    print('YES' if answer else 'NO')
