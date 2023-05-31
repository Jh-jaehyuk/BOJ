n = int(input())
parent = list(map(int, input().split()))
x = int(input())

tree = [[] for _ in range(n + 1)]
root = -1
leaf = 0

for i in range(n):
    if parent[i] == -1:
        root = i
    tree[parent[i]].append(i)


def dfs(node):
    global leaf

    if len(tree[node]) == 0:
        leaf += 1
        return leaf

    for i in range(len(tree[node])):
        if tree[node][i] == x:
            if len(tree[node]) == 1:
                leaf += 1
                return leaf
            else:
                continue
        else:
            dfs(tree[node][i])


if parent[x] == -1:
    print(0)
else:
    dfs(root)
    print(leaf)
