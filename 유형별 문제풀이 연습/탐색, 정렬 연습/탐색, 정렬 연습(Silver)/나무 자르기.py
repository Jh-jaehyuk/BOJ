n, m = map(int, input().split())
arr = list(map(int, input().split()))

left = 0
right = max(arr)
result = 0

while left <= right:
    total = 0
    mid = (left + right) // 2

    for i in arr:
        if i > mid:
            total += i - mid

    if total < m:
        right = mid - 1

    else:
        result = mid
        left = mid + 1

print(result)
