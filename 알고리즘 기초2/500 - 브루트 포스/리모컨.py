import sys

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
arr = set()
if m:
    arr = set(sys.stdin.readline().rstrip().split())

min_count = abs(n - 100)

# 1000000개의 채널을 돌면서 모든 채널에 대해서 누르는 횟수를 비교함.
for i in range(1000001):
    for j in str(i):
        if j in arr:
            break
    else:
        min_count = min(min_count, len(str(i)) + abs(i - n))

print(min_count)
