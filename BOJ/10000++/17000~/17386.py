x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())


def ccw(x1, y1, x2, y2, x3, y3):
    return (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1)


abc = ccw(x1, y1, x2, y2, x3, y3)
abd = ccw(x1, y1, x2, y2, x4, y4)
cda = ccw(x3, y3, x4, y4, x1, y1)
cdb = ccw(x3, y3, x4, y4, x2, y2)

if abc * abd <= 0 and cda * cdb <= 0:
    print(1)

else:
    print(0)
