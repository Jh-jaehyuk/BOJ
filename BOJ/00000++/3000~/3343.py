from math import lcm

n, a, b, c, d = map(int, input().split())
result = int(1e19)

if a * d > b * c:
    a, b, c, d = c, d, a, b

l = lcm(a, c)

for i in range(l // a):
    tmp = i * b

    if n - i * a > 0:
        tmp += (((n - i * a - 1) // c) + 1) * d
    result = min(result, tmp)

print(result)
