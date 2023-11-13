import sys

T = int(sys.stdin.readline())

for t in range(T):
    x, y = map(int, sys.stdin.readline().split())
    total = y - x
    day, tmp = 0, 0

    while tmp < total:
        day += 1
        _day = day // 2

        if day % 2 == 0:
            tmp = _day * (_day + 1)
        else:
            tmp = _day * (_day + 1) + (_day + 1)

    print(day)