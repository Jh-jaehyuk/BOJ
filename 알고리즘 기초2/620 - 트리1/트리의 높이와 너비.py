import sys
from collections import deque

n = int(sys.stdin.readline())

tree = [[-1, -1, -1] for _ in range(n + 1)]
for _ in range(n):
    root, left, right = map(int, sys.stdin.readline().split())
    tree[root][1] = left
    tree[root][2] = right
    tree[left][0] = n
    tree[right][0] = n

root = -1
for i in range(1, n + 1):
    if tree[i][0] == -1:
        root = i

visited = [[-1, -1] for _ in range(n + 1)]

def bfs(node):
    max_depth = 0
    queue = deque([node])
    visited[node][0] = 0
    while queue:
        root = queue.popleft()
        left = tree[root][1]
        right = tree[root][2]

        if left != -1:
            if visited[left][0] == -1:
                visited[left][0] = visited[root][0] + 1
                max_depth = max(visited[left][0], max_depth)
                queue.append(left)

        if right != -1:
            if visited[right][0] == -1:
                visited[right][0] = visited[root][0] + 1
                max_depth = max(visited[right][0], max_depth)
                queue.append(right)
    return max_depth

d = 0

def inorder(node):
    global d
    if tree[node][1] != -1:
        inorder(tree[node][1])
    d += 1
    visited[node][1] = d

    if tree[node][2] != -1:
        inorder(tree[node][2])

max_depth = bfs(root)
inorder(root)
max_d = 0
min_depth = int(1e9)

if n == 1:
    print(1)
    print(1)

else:
    for j in range(max_depth + 1):
        min_val = int(1e9)
        max_val = 0
        for i in range(1, n + 1):
            if j == visited[i][0]:
                min_val = min(visited[i][1], min_val)
                max_val = max(visited[i][1], max_val)

        if max_d < max_val - min_val + 1:
            min_depth = j + 1
            max_d = max_val - min_val + 1

    print(min_depth)
    print(max_d)
