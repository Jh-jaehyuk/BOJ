# 아마 set로 처리하면 더 빠를듯..?
import sys

def is_prime_number(n):
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True

arr = [False] * 1000001
for i in range(3, 1000001):
    arr[i] = is_prime_number(i)

while True:
    n = int(sys.stdin.readline())
    i = 0
    x = False
    if n == 0:
        break
    else:
        for i in range(3, 1000001 // 2 + 1):
            if arr[i] and arr[n - i]:
                print(f'{n} = {i} + {n - i}')
                x = True
                break
            if not x:
                print("Goldbach's conjecture is wrong")
