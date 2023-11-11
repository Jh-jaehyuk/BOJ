import sys

n = int(sys.stdin.readline())
arr = [tuple(map(int, sys.stdin.readline().split())) for _ in range(n)]
arr.sort()
arr.extend([(int(1e9) + 1, int(1e9) + 1)])

start, end = arr[0]
result = 0

for i in range(1, n + 1):
    if start <= arr[i][0] <= arr[i][1] <= end:
        continue

    if start <= arr[i][0] <= end <= arr[i][1]:
        end = arr[i][1]

    else:
        result += end - start
        start, end = arr[i]

print(result)
