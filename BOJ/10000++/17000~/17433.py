import sys
from math import gcd

T = int(sys.stdin.readline())


def solve():
    n = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().split()))

    if n == 1:
        print('INFINITY')
        return

    tmp = []

    for i in range(n - 1):
        if arr[i + 1] - arr[i]:
            tmp.append(arr[i + 1] - arr[i])

    if not tmp:
        print('INFINITY')
    else:
        g = tmp[0]

        for i in range(1, len(tmp)):
            g = gcd(g, tmp[i])

        print(g)


for t in range(T):
    solve()
