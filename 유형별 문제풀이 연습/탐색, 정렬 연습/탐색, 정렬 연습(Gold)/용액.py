import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
min_val = 1e10
left = 0
right = n - 1
result = []

while left < right:
    val = arr[left] + arr[right]

    if abs(val) <= min_val:
        min_val = abs(val)
        result = [arr[left], arr[right]]

    if val <= 0:
        left += 1
    else:
        right -= 1

print(*result)
