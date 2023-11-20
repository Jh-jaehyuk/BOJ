import sys

tmp = sys.stdin.read()
n, *arr = tmp.split()

for i in range(int(n)):
    arr[i] = int(arr[i][::-1])

print(*[i for i in sorted(arr)], sep="\n")