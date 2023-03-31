import sys

n, s = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
tmp = []
count = 0

def dfs(start):
    global count

    if tmp and sum(tmp) == s:
        count += 1

    for i in range(start, n):
        tmp.append(arr[i])
        dfs(i + 1)
        tmp.pop()

dfs(0)
print(count)
