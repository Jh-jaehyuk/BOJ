n = int(input())
arr = [0] + list(map(int, input().split()))
check = [0] * (n + 1)

for i in range(1, n + 1):
    check[arr[i]] = i

count = 1
result = -1
for i in range(1, n):
    if check[i] < check[i + 1]:
        count += 1
        result = max(result, count)
    else:
        count = 1

print(0 if result == -1 else n - result)
