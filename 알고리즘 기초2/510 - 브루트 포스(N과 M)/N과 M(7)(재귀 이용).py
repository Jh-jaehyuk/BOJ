import sys

n, m = map(int, sys.stdin.readline().split())

arr = sorted(list(map(int, sys.stdin.readline().split())))
tmp = []

def dfs():
    if len(tmp) == m:
        print(*tmp)
        return

    for i in range(n):
        tmp.append(arr[i])
        dfs()
        tmp.pop()

dfs()
