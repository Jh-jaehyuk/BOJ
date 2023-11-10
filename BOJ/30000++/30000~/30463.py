import sys
from itertools import combinations

n, K = map(int, sys.stdin.readline().rstrip().split())
arr = [sys.stdin.readline().rstrip() for _ in range(n)]


def Count(bit):
    if bit == 0:
        return 0
    return bit % 2 + Count(bit // 2)


result = 0
combi = list(combinations(arr, 2))
for c in combi:
    bit = 1 << 10
    x = ''.join(c)

    for i in range(20):
        bit |= (1 << int(x[i]))

    if Count(bit) == K + 1:
        result += 1

print(result)
