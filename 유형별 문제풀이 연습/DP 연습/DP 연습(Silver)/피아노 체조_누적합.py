import sys

n = int(sys.stdin.readline())
music = [0] + list(map(int, sys.stdin.readline().split()))
d = [0] * (n + 1)

for i in range(n):
    if music[i] > music[i + 1]:
        d[i + 1] = d[i] + 1
    else:
        d[i + 1] = d[i]

q = int(sys.stdin.readline())

for _ in range(q):
    x, y = map(int, sys.stdin.readline().split())
    print(d[y] - d[x])
