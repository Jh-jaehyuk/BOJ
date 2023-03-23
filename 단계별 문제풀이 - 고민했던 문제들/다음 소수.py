import sys
T = int(sys.stdin.readline())

def is_prime_number(x):
    if x == 0:
        return False
    elif x == 1:
        return False

    for i in range(2, int(x ** 0.5) + 1):
        if x % i == 0:
            return False
    return True

# n의 범위가 넓기 때문에 n 이상까지 모든 수를 판별하는 것은 불가능.
# 따라서 n을 1씩 키워가면서 그 값이 소수면 return 하게끔 해야함.
for _ in range(T):
    n = int(sys.stdin.readline())
    while not is_prime_number(n):
        n += 1
    print(n)
