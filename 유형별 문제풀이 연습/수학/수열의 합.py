N, L = map(int, input().split())

x, length = -1, 0

for i in range(L, 101):
    val = (N / i) - ((i - 1) / 2)
    if val == int(val) and val >= 0:
        x = int(val)
        length = i
        break

if x >= 0:
    print(*[x + i for i in range(length)])
else:
    print(-1)
