import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
d = arr[:]

for i in range(n):
    for j in range(i):
        if arr[i] > arr[j]:
            d[i] = max(d[i], d[j] + arr[i])

print(max(d))
