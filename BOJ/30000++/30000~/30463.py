import sys
from collections import defaultdict

n, K = map(int, sys.stdin.readline().split())
d = defaultdict(int)


def count_bit(bit):
    if bit == 0:
        return 0
    return bit % 2 + count_bit(bit // 2)


for _ in range(n):
    bit = 0
    x = sys.stdin.readline().rstrip()

    for i in range(10):
        bit |= (1 << int(x[i]))

    d[bit] += 1

result = 0
for i in d:
    for j in d:
        if i <= j and count_bit(i | j) == K:
            if i == j:
                result += (d[i] * (d[i] - 1)) // 2
            else:
                result += d[i] * d[j]

print(result)
