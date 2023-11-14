import sys
from bisect import bisect_left

m, n = map(int, sys.stdin.readline().split())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(m)]

for i in range(m):
    s = sorted(list(set(arr[i])))

    for j in range(n):
        arr[i][j] = bisect_left(s, arr[i][j])

result = 0

for i in range(m - 1):
    for j in range(i + 1, m):
        for k in range(n):
            if arr[i][k] != arr[j][k]:
                break
        else:
            result += 1

print(result)