import sys

n, k = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
tmp = []

for i in range(len(arr) - 1):
    tmp.append(arr[i + 1] - arr[i])
tmp.sort()

for _ in range(k - 1):
    tmp.pop()

print(sum(tmp))
