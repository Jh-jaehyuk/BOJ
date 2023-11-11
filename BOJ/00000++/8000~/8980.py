import sys

n, c = map(int, sys.stdin.readline().split())
m = int(sys.stdin.readline())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(m)]
arr.sort(key=lambda x: x[1])
check = [c] * (n + 1)

result = 0
for u, v, w in arr:
    min_val = c

    for i in range(u, v):
        min_val = min(min_val, check[i], w)

    for i in range(u, v):
        check[i] -= min_val

    result += min_val

print(result)
