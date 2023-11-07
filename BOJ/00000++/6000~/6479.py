import sys


def solve(n):
    tmp = 1
    result = [0] * 10

    for i in range(1, n + 1):
        tmp *= i

    str_n = str(tmp)

    for i in range(len(str_n)):
        result[int(str_n[i])] += 1

    print(f'{n}! --')
    print(' ' * 3, end='')
    for i in range(5):
        print(f'({i})', end='')
        if result[i] < 10:
            print(' ' * 4, end='')
        elif result[i] < 100:
            print(' ' * 3, end='')
        else:
            print(' ' * 2, end='')
        print(f'{result[i]}', end='')
        if i == 4:
            print(' ')
        else:
            print(' ' * 4, end='')

    print(' ' * 3, end='')
    for i in range(5, 10):
        print(f'({i})', end='')
        if result[i] < 10:
            print(' ' * 4, end='')
        elif result[i] < 100:
            print(' ' * 3, end='')
        else:
            print(' ' * 2, end='')
        print(f'{result[i]}', end='')
        if i == 9:
            print(' ')
        else:
            print(' ' * 4, end='')


while True:
    n = int(sys.stdin.readline())
    _ = sys.stdin.readline()

    if n == 0:
        break

    solve(n)