import sys

n = int(sys.stdin.readline())
data = list(map(int, sys.stdin.readline().split()))
add,sub, mul, div = map(int, sys.stdin.readline().split())

max_val = -int(1e9)
min_val = int(1e9)

def dfs(i, arr):
    global add, sub, mul, div, max_val, min_val

    if i == n:
        max_val = max(max_val, arr)
        min_val = min(min_val, arr)

    else:
        if add > 0:
            add -= 1
            dfs(i + 1, arr + data[i])
            add += 1

        if sub > 0:
            sub -= 1
            dfs(i + 1, arr - data[i])
            sub += 1

        if mul > 0:
            mul -= 1
            dfs(i + 1, arr * data[i])
            mul += 1

        if div > 0:
            div -= 1
            dfs(i + 1, int(arr / data[i]))
            div += 1

dfs(1, data[0])

print(max_val)
print(min_val)
