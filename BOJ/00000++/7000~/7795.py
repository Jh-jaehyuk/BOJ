import sys

T = int(sys.stdin.readline())


def solve():
    n, m = map(int, sys.stdin.readline().split())
    A = sorted(list(map(int, sys.stdin.readline().split())))
    B = sorted(list(map(int, sys.stdin.readline().split())))
    result = 0

    for i in range(n):
        for j in range(m - 1, -1, -1):
            if A[i] <= B[j]:
                continue

            result += (j + 1)
            break

    print(result)


for _ in range(T):
    solve()
