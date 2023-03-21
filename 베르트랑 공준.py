import sys

def is_prime_number(x):
    if x == 1:
        return False
    for i in range(2, int(x ** 0.5) + 1):
        if x % i == 0:
            return False
    return True

array = [i for i in range(2, 123456 * 2 + 1)]
l = []

for i in array:
    if is_prime_number(i):
        l.append(i)

while True:
    n = int(sys.stdin.readline())
    count = 0
    if n == 0:
        break
    for i in l:
        if i > n and i <= 2 * n:
            count += 1
    print(count)
