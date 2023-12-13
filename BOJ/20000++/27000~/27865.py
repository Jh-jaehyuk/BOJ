import sys

n = int(input())

for i in range(20000):
    print('? 1', flush=True)

    res = input()
    if res == 'Y':
        print('! 1')
        sys.stdout.flush()
        exit(0)
