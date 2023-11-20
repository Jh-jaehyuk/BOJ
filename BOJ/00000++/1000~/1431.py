import sys

n = int(sys.stdin.readline())
arr = []

for _ in range(n):
    total = 0
    s = sys.stdin.readline().rstrip()
    length = len(s)

    for i in range(length):
        if s[i].isdigit():
            total += int(s[i])

    arr.append((s, length, total))

arr.sort(key=lambda x: (x[1], x[2], x))

print(*[arr[i][0] for i in range(n)], sep="\n")