import sys

n = int(sys.stdin.readline())
arr = list()

for _ in range(n):
    a = list(sys.stdin.readline().rstrip().split())
    if 'push' in a:
        arr.append(int(a[1]))
    elif 'top' in a:
        if len(arr) == 0:
            print(-1)
        else:
            print(arr[-1])
    elif 'size' in a:
        print(len(arr))
    elif 'empty' in a:
        if len(arr) == 0:
            print(1)
        else:
            print(0)
    elif 'pop' in a:
        if len(arr) == 0:
            print(-1)
        else:
            print(arr[-1])
            arr.pop()
