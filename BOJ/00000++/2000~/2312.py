import sys

T = int(sys.stdin.readline())


def solve():
    n = int(sys.stdin.readline())

    for i in range(2, int(n ** 0.5) + 1):
        count = 0
        while n % i == 0:
            n //= i
            count += 1

        if count:
            print(i, count)

    if n > 1:
        print(n, 1)


for _ in range(T):
    solve()
