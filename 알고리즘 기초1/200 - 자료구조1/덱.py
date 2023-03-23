import sys
from collections import deque

n = int(sys.stdin.readline())
arr = deque()

for _ in range(n):
    a = list(sys.stdin.readline().rstrip().split())

    if 'push_front' in a:
        arr.appendleft(a[1])

    elif 'push_back' in a:
        arr.append(a[1])

    elif 'pop_front' in a:
        if arr:
            print(arr.popleft())
        else:
            print(-1)

    elif 'pop_back' in a:
        if arr:
            print(arr.pop())
        else:
            print(-1)

    elif 'size' in a:
        print(len(arr))

    elif 'empty' in a:
        if arr:
            print(0)
        else:
            print(1)

    elif 'front' in a and len(a) == 1:
        if arr:
            print(arr[0])
        else:
            print(-1)

    elif 'back' in a and len(a) == 1:
        if arr:
            print(arr[-1])
        else:
            print(-1)
