# Pypy 이용 시 메모리 부족이 발생하므로 Python3로 제출 할 것.
import sys

m = int(sys.stdin.readline())
bit = 0

for _ in range(m):
    tmp = sys.stdin.readline().rstrip().split()

    if tmp[0] == 'all':
        bit = (1 << 20) - 1
    elif tmp[0] == 'empty':
        bit = 0
    else:
        a = tmp[0]
        b = int(tmp[1]) - 1

        if a == 'add':
            bit |= (1 << b)

        elif a == 'remove':
            bit &= ~(1 << b)

        elif a == 'check':
            if bit & (1 << b) == 0:
                print(0)
            else:
                print(1)

        elif a == 'toggle':
            bit = bit ^ (1 << b)
