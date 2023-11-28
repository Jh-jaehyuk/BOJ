import sys
sys.setrecursionlimit(10 ** 5)

n, start = map(int, input().split())
distance = [list(map(int, input().split())) for _ in range(n)]
visited = [False] * n

for k in range(n):
    for i in range(n):
        for j in range(n):
            distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])

result = int(1e9)

def DFS(node, cost, depth):
    global result

    if depth == n:
        result = min(result, cost)
        return

    for i in range(n):
        if not visited[i]:
            visited[i] = True
            DFS(i, cost + distance[node][i], depth + 1)
            visited[i] = False


DFS(start, 0, 0)
print(result)