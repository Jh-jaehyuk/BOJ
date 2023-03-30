import sys

n, m = map(int, sys.stdin.readline().split())
arr = set(map(int, sys.stdin.readline().split()))
length = len(arr)
arr = sorted(list(arr))
tmp = []

def dfs():
    if len(tmp) == m:
        print(*tmp)
        return

    for i in range(length):
        tmp.append(arr[i])
        dfs()
        tmp.pop()
dfs()
