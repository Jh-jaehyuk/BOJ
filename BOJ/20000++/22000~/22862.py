import sys

n, k = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))

max_val = 0
start, end = 0, 0
now = 0
count = 0

while start <= end < n:
    while count <= k and end < n:
        if arr[end] % 2 == 1:
            count += 1
        end += 1
        now += 1
        max_val = max(max_val, end - start - count)

    while count > k:
        if arr[start] % 2 == 1:
            count -= 1
        start += 1

print(max_val)