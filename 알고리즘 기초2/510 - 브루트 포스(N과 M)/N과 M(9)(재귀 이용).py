import sys

n, m = map(int, sys.stdin.readline().split())
arr = sorted(list(map(int, sys.stdin.readline().split())))
tmp = []
visited = [False] * n

def dfs():
    if len(tmp) == m:
        print(*tmp)
        return
    tmp2 = 0

    for i in range(n):
        if not visited[i] and tmp2 != arr[i]:
            visited[i] = True
            tmp.append(arr[i])
            tmp2 = arr[i]
            dfs()
            visited[i] = False
            tmp.pop()
dfs()
