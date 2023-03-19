import sys
m = int(sys.stdin.readline())
n = int(sys.stdin.readline())

def is_prime_number(n):
    if n == 1:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True

def count_prime_number(m, n):
    prime = []
    if m == 1:
        for i in range(m + 1, n + 1):
            if is_prime_number(i):
                prime.append(i)
    else:
        for i in range(m, n + 1):
            if is_prime_number(i):
                prime.append(i)
    return prime

if m == n:
    if is_prime_number(n):
        print(m)
        print(m)
        quit()
    else:
        print(-1)
        quit()

prime = count_prime_number(m, n)

if prime == []:
    print(-1)
    quit()

else:
    print(sum(prime))
    print(min(prime))
