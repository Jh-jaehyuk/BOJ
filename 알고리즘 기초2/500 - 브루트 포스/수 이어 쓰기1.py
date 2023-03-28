import sys

n = int(sys.stdin.readline())
length = n

if n > 9:
    length = 0
    x = len(str(n))
    for i in range(1, x):
        length += (9 * (10 ** (i - 1))) * i

    length += x * (n - (10 ** (x - 1)) + 1)

print(length)
