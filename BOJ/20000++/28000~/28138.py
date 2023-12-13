n, r = map(int, input().split())

result = 0

for i in range(1, int((n - r) ** 0.5) + 1):
    if (n - r) % i == 0:
        if i > r:
            result += i

        if (n - r) // i > r and i * i != n - r:
            result += (n - r) // i

print(result)