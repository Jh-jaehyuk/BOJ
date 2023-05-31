import sys

n = int(sys.stdin.readline())
stair = [0]

for _ in range(n):
    stair.append(int(sys.stdin.readline()))

d = [0] * 301

if n == 1:
    print(stair[1])
    quit(0)
elif n == 2:
    print(stair[1] + stair[2])
    quit(0)

d[1] = stair[1]
d[2] = stair[1] + stair[2]
d[3] = max(stair[1], stair[2]) + stair[3]

for i in range(4, n + 1):
    d[i] = max(d[i - 3] + stair[i - 1] + stair[i], d[i - 2] + stair[i])

print(d[n])
