n = int(input())
arr = list(map(int, input().split()))

result = -1

for i in range(n):
    left = 0
    right = 0
    tmp = int(1e10)
    x1, y1 = i, arr[i]

    for j in range(i - 1, -1, -1):
        x2, y2 = j, arr[j]
        val = (y2 - y1) / (x2 - x1)

        if tmp > val:
            tmp = val
            left += 1

    tmp = -int(1e10)
    for j in range(i + 1, n):
        x2, y2 = j, arr[j]
        val = (y2 - y1) / (x2 - x1)

        if tmp < val:
            tmp = val
            right += 1

    result = max(result, left + right)

print(result)