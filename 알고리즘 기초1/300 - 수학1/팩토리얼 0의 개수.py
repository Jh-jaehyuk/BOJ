import sys

n = int(sys.stdin.readline())

def factorial(x):
    if x == 0 or x == 1:
        return 1
    else:
        return x * factorial(x - 1)

x = factorial(n)
count = 0

for i in str(x)[::-1]:
    if i == '0':
        count += 1
    else:
        break

print(count)
