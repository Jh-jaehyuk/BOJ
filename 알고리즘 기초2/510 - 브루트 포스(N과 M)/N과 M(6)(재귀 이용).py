import sys

n, m = map(int, sys.stdin.readline().split())

arr = sorted(list(map(int, sys.stdin.readline().split())))
tmp = []

def dfs(start):
    if len(tmp) == m:
        print(*tmp)
        return

    for i in range(start, n):
        if arr[i] not in tmp:
            tmp.append(arr[i])
            dfs(i + 1)
            tmp.pop()

dfs(0)
