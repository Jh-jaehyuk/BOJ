import sys

T = int(sys.stdin.readline())

for _ in range(T):
    l, n = map(int, sys.stdin.readline().split())
    tmp = sorted([int(sys.stdin.readline()) for _ in range(n)])
    max_val = max(l - tmp[0], tmp[-1])
    min_val = -1

    for i in tmp:
        if i < l / 2:
            min_val = max(min_val, i)
        else:
            min_val = max(min_val, l - i)

    print(min_val, max_val)