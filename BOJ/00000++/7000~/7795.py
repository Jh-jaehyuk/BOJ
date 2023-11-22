import sys
from bisect import bisect_right

T = int(sys.stdin.readline())


def solve():
    n, m = map(int, sys.stdin.readline().split())
    A = list(map(int, sys.stdin.readline().split()))
    B = sorted(list(map(int, sys.stdin.readline().split())))
    result = 0

    for i in A:
        tmp = bisect_right(B, i - 1)
        result += tmp

    print(result)


for _ in range(T):
    solve()
