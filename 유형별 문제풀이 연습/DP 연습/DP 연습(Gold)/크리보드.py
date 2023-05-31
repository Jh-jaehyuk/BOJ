n = int(input())

d = [0] * 101
for i in range(1, 7):
    d[i] = i

for i in range(7, n + 1):
    for j in range(3, i):
        d[i] = max(d[i], d[i - j] * (j - 1))

print(d[n])
