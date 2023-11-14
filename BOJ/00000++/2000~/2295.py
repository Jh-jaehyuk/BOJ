import sys

n = int(sys.stdin.readline())
s = set()
_s = set()

for _ in range(n):
    x = int(sys.stdin.readline())
    s.add(x)

for i in s:
    for j in s:
        _s.add(i + j)

ls = sorted(list(s))
max_val = ls[-1]

result = -1

for i in _s:
    start, end = 0, len(ls) - 1

    while start <= end:
        mid = (start + end) // 2
        tmp = i + ls[mid]

        if tmp in s:
            result = max(result, tmp)

        if tmp < max_val:
            start = mid + 1
        else:
            end = mid - 1

print(result)