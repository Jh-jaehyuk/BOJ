import random

check = set()
A, B = 0, 0

for i in range(19997):
    x = random.randint(1, 10001)

    while x in check:
        x = random.randint(1, 10001)
    check.add(x)

    if not A:
        print("? A", x, flush=True)
    else:
        print("? B", x, flush=True)
    res = int(input())

    if res:
        if not A:
            A = x
            check.clear()
        else:
            B = x
            print("!", A + B, flush=True)
            exit(0)
