def is_prime_number(n): # n이 소수인지 아닌지 판별하는 함수
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True

def count_prime_number(n): # n까지 소수의 개수를 세주는 함수
    prime = []
    for i in range(2, n + 1):
        if is_prime_number(i):
            prime.append(i)
    return prime

import sys

T = int(sys.stdin.readline())
array = count_prime_number(10000)

for _ in range(T):
    n = int(sys.stdin.readline())
    if n // 2 in array:
        print(n // 2, n // 2)
    else:
        array = sorted(array, key=lambda x:abs((n // 2) - x))
        for i in range(len(array)):
            a = array[i]
            if n - a in array:
                b = n - a
                if a > b:
                    print(b, a)
                    break
                else:
                    print(a, b)
                    break
