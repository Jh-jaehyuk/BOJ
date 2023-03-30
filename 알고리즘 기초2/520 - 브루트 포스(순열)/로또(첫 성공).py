import sys

tmp = []

def dfs(start):
    if len(tmp) == 6:
        print(*tmp)
        return

    for i in range(start, k):
        if arr[i] not in tmp:
            tmp.append(arr[i])
            dfs(i)
            tmp.pop()

while True:
    arr = list(map(int, sys.stdin.readline().split()))
    if arr == [0]:
        break

    k = arr[0]
    arr = arr[1:]
    dfs(0)
    print() # 한 줄 공백넣기
