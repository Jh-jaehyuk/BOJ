x, y = map(int, input().split())
total = y - x
day = 0
tmp = 0

while tmp < total:
    day += 1
    _day = day // 2

    if day % 2 == 0:
        tmp = _day * (_day + 1)

    else:
        tmp = _day * (_day + 1) + (_day + 1)

print(day)