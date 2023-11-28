import sys


def solve(idx):
    n = int(sys.stdin.readline())
    k = int(sys.stdin.readline())
    parent = [i for i in range(n)]

    for _ in range(k):
        a, b = map(int, sys.stdin.readline().split())

        if find_parent(parent, a) != find_parent(parent, b):
            union_parent(parent, a, b)

    m = int(sys.stdin.readline())

    print(f"Scenario {idx}:")
    for _ in range(m):
        a, b = map(int, sys.stdin.readline().split())

        if find_parent(parent, a) == find_parent(parent, b):
            print(1)
        else:
            print(0)
    print()


def find_parent(parent, x):
    if parent[x] == x:
        return x

    return find_parent(parent, parent[x])


def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b


T = int(sys.stdin.readline())
for t in range(1, T + 1):
    solve(t)
