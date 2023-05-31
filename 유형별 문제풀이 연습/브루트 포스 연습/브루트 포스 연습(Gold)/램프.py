import sys

n, m = map(int, sys.stdin.readline().split())
lamp = [list(sys.stdin.readline().strip()) for _ in range(n)]
K = int(sys.stdin.readline())

max_val = 0

for i in range(n):
    count = 0
    for j in lamp[i]:
        if j == '0':
            count += 1

    val = 0
    if count <= K and count % 2 == K % 2:
        for k in range(n):
            if lamp[i] == lamp[k]:
                val += 1
    max_val = max(max_val, val)

print(max_val)
