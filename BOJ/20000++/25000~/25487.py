import sys

T = int(sys.stdin.readline())

for _ in range(T):
    a, b, c = map(int, sys.stdin.readline().split())
    print(min(a, b, c))
