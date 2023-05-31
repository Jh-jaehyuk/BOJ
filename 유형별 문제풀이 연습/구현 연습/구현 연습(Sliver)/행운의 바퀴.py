import sys

n, k = map(int, sys.stdin.readline().split())
arr = ['?'] * n
idx = 0

for _ in range(k):
    a, b = sys.stdin.readline().rstrip().split(' ')
    a = int(a)
    idx += a
    if idx >= n:
        idx %= n
    if arr[idx] == '?' and b not in arr:
        arr[idx] = b
    elif arr[idx] == b:
        pass
    else:
        print('!')
        quit(0)

for _ in range(n):
    print(arr[idx], end='')
    idx = (idx - 1) % n
