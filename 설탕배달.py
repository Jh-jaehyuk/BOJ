import sys
n = int(sys.stdin.readline())
count = 0

while n >= 3:
    if n % 5 == 0:
        count += n // 5
        print(count)
        quit()

    else:
        count += 1
        n -= 3

if n == 0:
    print(count)
else:
    print(-1)
