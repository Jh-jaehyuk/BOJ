import sys


n = int(sys.stdin.readline())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
arr.sort(key=lambda x: x[0])
d = [1] * n

for i in range(1, n):
    for j in range(i):
        if arr[i][1] > arr[j][1]:
            d[i] = max(d[i], d[j] + 1)
print(n - max(d))
