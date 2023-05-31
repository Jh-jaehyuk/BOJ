import sys

n, k = map(int, sys.stdin.readline().split())
money = []
for _ in range(n):
    money.append(int(sys.stdin.readline()))

d = [0] * (k + 1)
d[0] = 1

for i in money:
    for j in range(1, k + 1):
        if j >= i:
            d[j] += d[j - i]

print(d[k])
