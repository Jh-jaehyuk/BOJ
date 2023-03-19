import sys
T = int(input())

for _ in range(T):
    h, w, n = map(int, sys.stdin.readline().split())
    a, b = divmod(n, h)

    if b == 0:
        print(str(h) + str('%02d'%(a)))
    else:
        print(str(b) + str('%02d'%(a + 1)))
