import sys

n = int(sys.stdin.readline())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
INF = int(1e10)
visited = [False] * n
distance = [INF] * n


def get_smallest_node(n):
    for i in range(n):
        if not visited[i]:
            v = i
            break

    for i in range(n):
        if not visited[i] and distance[i] < distance[v]:
            v = i

    return v


def prim(start):
    distance[start] = 0

    for i in range(n):
        node = get_smallest_node(n)
        visited[node] = True

        for j in range(n):
            if board[node][j] != INF:
                if not visited[j] and board[node][j] < distance[j]:
                    distance[j] = board[node][j]


prim(0)
print(sum(distance))
