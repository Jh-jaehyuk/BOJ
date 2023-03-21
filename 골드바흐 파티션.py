import sys

T = int(sys.stdin.readline())
prime = [True] * 1000001

for i in range(2, int(1000000 * 0.5) + 1):
    if prime[i]:
        for j in range(i * 2, 1000000, i):
            prime[j] = False

for _ in range(T):
    count = 0
    x = int(sys.stdin.readline())
    for i in range(2, x // 2 + 1):
        if prime[i] and prime[x - i]:
            count += 1
    print(count)
