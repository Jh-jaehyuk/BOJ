import sys

n, k = map(int, sys.stdin.readline().split())
check = [0] * 1000001
min_val = int(1e9)
max_val = -1
flag = False

for _ in range(n):
    s, e = map(int, sys.stdin.readline().split())
    min_val = min(min_val, s)
    max_val = max(max_val, e)

    for i in range(s, e):
        check[i] += 1

start, end = 0, 0
tmp = 0
flag = False

while start <= end <= max_val:
    if tmp == k:
        flag = True
        break

    elif tmp > k:
        tmp -= check[start]
        start += 1

    else:
        tmp += check[end]
        end += 1

if flag:
    print(start, end)
else:
    print(0, 0)
