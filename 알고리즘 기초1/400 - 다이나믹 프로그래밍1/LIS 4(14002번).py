import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
d = [1] * n

for i in range(n):
    for j in range(i):
        if arr[i] > arr[j]:
            d[i] = max(d[i], d[j] + 1)
print(max(d))

x = max(d)
l = []
for i in range(n - 1, -1, -1):
    if d[i] == x:
        l.append(arr[i])
        x -= 1
l.reverse()
print(*l)
