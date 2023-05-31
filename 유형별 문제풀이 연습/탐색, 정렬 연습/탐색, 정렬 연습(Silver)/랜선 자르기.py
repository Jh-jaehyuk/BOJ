import sys

k, n = map(int, sys.stdin.readline().split())
arr = [int(sys.stdin.readline()) for _ in range(k)]

left = 1
right = max(arr)
result = 0

while left <= right:
    mid = (left + right) // 2
    s = 0
    for i in arr:
        s += i // mid

    if s >= n:
        left = mid + 1
        if mid > result:
            result = mid

    else:
        right = mid - 1

print(result)
