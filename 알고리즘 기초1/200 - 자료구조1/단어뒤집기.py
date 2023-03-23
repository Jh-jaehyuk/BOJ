import sys

n = int(sys.stdin.readline())

for _ in range(n):
    arr = list(sys.stdin.readline().rstrip().split())
    for i in arr:
        print(i[::-1], end=' ')
