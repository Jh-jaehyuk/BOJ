import sys

arr = [[-1] * 26 for _ in range(10000 * 500 + 1)]
idx = 2

n, m = map(int, sys.stdin.readline().split())


def insert(s):
    global idx
    now = 1

    for i in s:
        if arr[now][ord(i) - ord('a')] == -1:
            arr[now][ord(i) - ord('a')] = idx
            idx += 1
        now = arr[now][ord(i) - ord('a')]


def check(s):
    now = 1

    for i in s:
        if arr[now][ord(i) - ord('a')] == -1:
            return 0
        now = arr[now][ord(i) - ord('a')]
    return 1


for _ in range(n):
    insert(sys.stdin.readline().rstrip())

result = 0
for _ in range(m):
    result += check(sys.stdin.readline().rstrip())

print(result)