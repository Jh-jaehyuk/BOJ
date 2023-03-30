import sys

n = int(sys.stdin.readline())
l = [i for i in range(n)]
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
tmp = []
tmp2 = []
answer = []

def dfs(start):
    if len(tmp) == n // 2:
        x = 0
        y = 0
        tmp2 = list(set(l) - set(tmp))
        for i in tmp:
            for j in tmp:
                if i != j:
                    x += arr[i][j]
        for i in tmp2:
            for j in tmp2:
                if i != j:
                    y += arr[i][j]
        answer.append(abs(x - y))
        return

    for i in range(start, n):
        if l[i] not in tmp:
            tmp.append(l[i])
            dfs(i + 1)
            tmp.pop()

dfs(0)
print(min(answer))
