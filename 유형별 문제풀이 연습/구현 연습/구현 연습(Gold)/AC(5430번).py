import sys
from collections import deque

T = int(sys.stdin.readline())

for _ in range(T):
    p = sys.stdin.readline().rstrip()
    n = int(sys.stdin.readline())
    x = sys.stdin.readline().rstrip()[1:-1]
    if ',' in x:
        arr = list(map(int, x.split(',')))
    elif x == '':
        arr = []
    else:
        arr = [int(x)]

    arr = deque(arr)
    count = 0
    flag = True
    for i in p:
        if i == 'R':
            count += 1
        elif i == 'D':
            if arr:
                if count % 2 == 0:
                    arr.popleft()
                else:
                    arr.pop()
            else:
                print('error')
                flag = False
                break

    if flag:
        if count % 2 == 0:
            print('[', end='')
            print(*arr, sep=',', end='')
            print(']')
        else:
            arr = list(arr)
            print('[', end='')
            print(*arr[::-1], sep=',', end='')
            print(']')
