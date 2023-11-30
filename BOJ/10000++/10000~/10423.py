import sys

n, m, k = map(int, sys.stdin.readline().split())
check = set(map(int, sys.stdin.readline().split()))
parent = [i for i in range(n + 1)]
edges = []

for _ in range(m):
    u, v, w = map(int, sys.stdin.readline().split())
    edges.append((w, u, v))

edges.sort()


def find_parent(x):
    if x == parent[x]:
        return x
    return find_parent(parent[x])


def union_parent(a, b):
    a = find_parent(a)
    b = find_parent(b)

    if a in check:
        parent[b] = a

    elif b in check:
        parent[a] = b

    else:
        if a < b:
            parent[b] = a
        else:
            parent[a] = b


result = 0
for cost, start, end in edges:
    ps = find_parent(start)
    pe = find_parent(end)

    if ps != pe:
        if ps in check and pe in check:
            continue
        union_parent(start, end)
        result += cost

    for i in range(1, n + 1):
        if parent[i] not in check:
            break
    else:
        break

print(result)