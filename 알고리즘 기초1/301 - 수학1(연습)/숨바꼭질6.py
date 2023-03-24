# 리스트에 있는 모든 수의 최대공약수를 구하는 문제

import sys

def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)

n, s = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))

if n == 1:
    print(arr[0] - s)

else:
    arr.append(s)
    arr = sorted(arr)
    arr2 = [arr[i] - arr[i-1] for i in range(1, len(arr))]
    x = gcd(arr2[0], arr2[1])

    for i in range(2, len(arr2)):
        x = gcd(x, arr2[i])

    print(x)
