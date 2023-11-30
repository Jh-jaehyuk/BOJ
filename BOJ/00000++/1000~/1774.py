import sys
from math import sqrt

n, m = map(int, sys.stdin.readline().split())
points = []
edges = []
parent = [i for i in range(n)]

for _ in range(n):
    points.append(list(map(int, sys.stdin.readline().split())))


def get_distance(x1, y1, x2, y2):
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)


for i in range(n):
    for j in range(i + 1, n):
        cost = get_distance(points[i][0], points[i][1], points[j][0], points[j][1])
        edges.append((cost, i, j))

edges.sort()


def find_parent(x):
    if x == parent[x]:
        return x
    return find_parent(parent[x])


def union_parent(a, b):
    a = find_parent(a)
    b = find_parent(b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b


count = 0
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    a -= 1
    b -= 1

    if find_parent(a) != find_parent(b):
        union_parent(a, b)
        count += 1

result = 0

for cost, start, end in edges:
    if find_parent(start) != find_parent(end):
        result += sqrt(cost)
        count += 1
        union_parent(start, end)

    if count == n - 1:
        break

print(f"{result:.2f}")
