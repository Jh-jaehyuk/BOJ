import sys

T = int(sys.stdin.readline())

for _ in range(T):
    s = sys.stdin.readline().rstrip()
    count = 0
    for i in s:
        if i == '(':
            count += 1
        else:
            count -= 1

        if count < 0:
            print('NO')
            break

    if count >= 0:
        if count == 0:
            print('YES')
        else:
            print('NO')
