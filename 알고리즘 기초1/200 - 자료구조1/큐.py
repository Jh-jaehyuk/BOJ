import sys
from collections import deque

n = int(sys.stdin.readline())
arr = deque()

for _ in range(n):
    a = list(sys.stdin.readline().rstrip().split())

    if 'push' in a:
        arr.append(a[1])

    elif 'pop' in a:
        if len(arr) != 0:
            x = arr.popleft()
            print(x)
        else:
            print(-1)

    elif 'size' in a:
        print(len(arr))

    elif 'empty' in a:
        if len(arr) == 0:
            print(1)
        else:
            print(0)

    elif 'front' in a:
        if len(arr) == 0:
            print(-1)
        else:
            print(arr[0])

    elif 'back' in a:
        if len(arr) == 0:
            print(-1)
        else:
            print(arr[-1])
