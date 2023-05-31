import sys

n, m = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
d = [0] * (n + 1)
d[1] = arr[0]

for i in range(2, n + 1):
    d[i] = d[i - 1] + arr[i - 1]

for _ in range(m):
    i, j = map(int, sys.stdin.readline().split())
    print(d[j] - d[i - 1])
