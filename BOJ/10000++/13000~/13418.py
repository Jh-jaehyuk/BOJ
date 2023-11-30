import sys

n, m = map(int, sys.stdin.readline().split())
edges = []
_, _, val = map(int, sys.stdin.readline().split())

for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    edges.append((c, a, b))

edges.sort()


def find_parent(parent, x):
    if x == parent[x]:
        return x
    return find_parent(parent, parent[x])


def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b


def kruskal(arr, val):
    count = 0
    tmp = 0
    parent = [i for i in range(n + 1)]

    for cost, start, end in arr:
        if find_parent(parent, start) != find_parent(parent, end):
            tmp += cost
            count += 1
            union_parent(parent, start, end)

        if count == n - 1:
            break

    tmp = (n - 1) - tmp

    if val == 0:
        tmp += 1

    return tmp


val1 = kruskal(edges, val)
val2 = kruskal(edges[::-1], val)

print(val1 * val1 - val2 * val2)