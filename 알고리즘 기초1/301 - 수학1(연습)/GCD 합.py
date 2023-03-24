import sys

def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)

T = int(sys.stdin.readline())

for _ in range(T):
    arr = list(map(int, sys.stdin.readline().split()))
    n = arr[0]
    arr = arr[1:]
    answer = 0
    for i in range(n):
        for j in range(i + 1, n):
            answer += gcd(arr[i], arr[j])
    print(answer)
