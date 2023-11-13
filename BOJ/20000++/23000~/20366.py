n = int(input())
arr = sorted(list(map(int, input().split())))
result = int(1e10)

for i in range(n - 1):
    for j in range(n - 1, i, -1):
        start, end = i + 1, j - 1

        while start < end:
            val1 = arr[i] + arr[j]
            val2 = arr[start] + arr[end]
            val = val1 - val2

            result = min(result, abs(val))

            if val > 0:
                start += 1
            else:
                end -= 1

print(result)