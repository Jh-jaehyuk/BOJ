import sys

s1 = set()
s2 = set()

for i in range(2, 300001):
    if i % 7 == 1 or i % 7 == 6:
        s1.add(i)

for i in s1:
    for j in range(2, int(i ** 0.5) + 1):
        if i % j == 0:
            if j % 7 == 1 or j % 7 == 6:
                s2.add(i)

s = s1 - s2

while True:
    x = int(sys.stdin.readline())
    result = []
    if x == 1:
        break

    for i in s:
        if x % i == 0:
            result.append(i)

    print(f'{x}:', end=' ')
    print(*result)
