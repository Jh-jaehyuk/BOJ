import random

numlist = list(i for i in range(1, 10001))
random.shuffle(numlist)
A, B = 0, 0

for x in numlist:
    print('? A', x)
    res = int(input())
    if res:
        A = x
        break

for x in numlist:
    print('? B', x)
    res = int(input())
    if res:
        B = x
        break

print('!', A + B)