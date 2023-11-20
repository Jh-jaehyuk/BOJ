import sys

n, m = map(int, sys.stdin.readline().split())
parent = [i for i in range(n + 1)]


def find_parent(x):
    if parent[x] == x:
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
    u, v = map(int, sys.stdin.readline().split())

    if find_parent(u) != find_parent(v):
        union_parent(u, v)
    else:
        count += 1


p = set()

for i in range(1, n + 1):
    p.add(find_parent(i))

print(count + len(p) - 1)