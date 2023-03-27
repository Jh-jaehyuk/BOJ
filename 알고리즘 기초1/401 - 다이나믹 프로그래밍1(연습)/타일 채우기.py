import sys

n = int(sys.stdin.readline())
d = [0] * (n + 1)
if n > 1:
    d[2] = 3

for i in range(4, n + 1):
    if i % 2 == 0:
        d[i] += 3 * d[i - 2]
        for j in range(i - 4, -1, -2):
            d[i] += 2 * d[j]
        d[i] += 2

print(d[n])
