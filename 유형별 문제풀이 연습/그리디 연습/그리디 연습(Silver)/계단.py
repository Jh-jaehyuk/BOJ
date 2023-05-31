import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

length = 0
max_val = 0

for i in arr:
    if length + 1 <= i:
        length += 1
    else:
        length = i
    max_val = max(max_val, length)
print(max_val)
