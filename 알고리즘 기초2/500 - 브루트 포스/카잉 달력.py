import sys

def solution(m, n, x, y):
    k = x
    while k <= m * n:
        if (k - x) % m == 0 and (k - y) % n == 0:
            return k
        k += m
    return -1

T = int(sys.stdin.readline())

for _ in range(T):
    m, n, x, y = map(int, sys.stdin.readline().split())
    print(solution(m, n, x, y))

# 어떻게 시간 초과를 피해갈 것인가가 중요함.
