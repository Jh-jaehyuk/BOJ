import sys

n = int(sys.stdin.readline())
arr = [int(sys.stdin.readline()) for _ in range(n)]

result = 0
now = arr[-1] - 1

for i in range(n - 2, -1, -1):
    if arr[i] > now:
        result += arr[i] - now
        now -= 1
    else:
        now = arr[i] - 1

print(result)