import sys


k = int(sys.stdin.readline())
d = [[0, 0] for _ in range(k + 1)]
d[0] = [1, 0]
d[1] = [0, 1]

for i in range(2, k + 1):
    d[i][0] = d[i - 1][0] + d[i - 2][0]
    d[i][1] = d[i - 1][1] + d[i - 2][1]

print(*d[k])
