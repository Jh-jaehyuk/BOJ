import sys

n, m = map(int, sys.stdin.readline().split())
money = []

for _ in range(n):
    money.append(int(sys.stdin.readline()))

left, right = min(money), sum(money)
max_val = max(money)
min_val = int(1e9)

while left <= right:
    mid = (left + right) // 2
    tmp = 0
    count = 0
    if mid < max_val:
        left = mid + 1
        continue

    for i in money:
        if tmp < i:
            tmp = mid
            count += 1
        if count > m:
            left = mid + 1
            continue
        tmp -= i

    if count <= m:
        min_val = min(min_val, mid)
        right = mid - 1

print(min_val)
