import sys
import math


def init(arr, tree, node, start, end):
    if start == end:
        tree[node] = arr[start]

    else:
        init(arr, tree, node * 2, start, (start + end) // 2)
        init(arr, tree, node * 2 + 1, (start + end) // 2 + 1, end)
        tree[node] = min(tree[node * 2], tree[node * 2 + 1])


def update(arr, tree, node, start, end, idx, val):
    if idx < start or idx > end:
        return

    if start == end:
        arr[idx] = val
        tree[node] = val
        return

    update(arr, tree, node * 2, start, (start + end) // 2, idx, val)
    update(arr, tree, node * 2 + 1, (start + end) // 2 + 1, end, idx, val)
    tree[node] = min(tree[node * 2], tree[node * 2 + 1])


def solve(tree, node, start, end, left, right):
    if left > end or right < start:
        return -1

    if left <= start and end <= right:
        return tree[node]

    left_min = solve(tree, node * 2, start, (start + end) // 2, left, right)
    right_min = solve(tree, node * 2 + 1, (start + end) // 2 + 1, end, left, right)

    if left_min == -1:
        return right_min

    elif right_min == -1:
        return left_min

    else:
        return min(left_min, right_min)


n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
h = math.ceil(math.log2(n))
tree_size = 1 << (h + 1)
tree = [0] * tree_size
init(arr, tree, 1, 0, n - 1)
m = int(sys.stdin.readline())

for _ in range(m):
    command, i, j = map(int, sys.stdin.readline().split())

    if command == 1:
        update(arr, tree, 1, 0, n - 1, i - 1, j)

    else:
        print(solve(tree, 1, 0, n - 1, i - 1, j - 1))
