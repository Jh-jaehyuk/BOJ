import sys

e, s, m = map(int, sys.stdin.readline().split())

a, b, c = 1, 1, 1
count = 1

while True:
    if a > 15:
        a = 1
    if b > 28:
        b = 1
    if c > 19:
        c = 1

    if a == e and b == s and c == m:
        break
    else:
        a += 1
        b += 1
        c += 1
        count += 1

print(count)
