import sys
from math import sqrt

n, r = map(int, sys.stdin.readline().split())
coords = [tuple(map(int, sys.stdin.readline().split())) for _ in range(n)]

max_count = -1
result = (-101, -101)

for x in range(-100, 101):
    for y in range(-100, 101):
        count = 0
        for xi, yi in coords:
            if sqrt((x - xi) * (x - xi) + (y - yi) * (y - yi)) <= r:
                count += 1

        if count > max_count:
            max_count = count
            result = (x, y)

print(*result)