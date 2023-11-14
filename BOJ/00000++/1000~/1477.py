n, m, l = map(int, input().split())
tmp = list(map(int, input().split())) + [0, l]
tmp.sort()
arr = [0] * (n + 1)

for i in range(n + 1):
    arr[i] = tmp[i + 1] - tmp[i] - 1

start, end = 1, l - 1
result = int(1e9)

while start <= end:
    mid = (start + end) // 2
    count = 0

    for i in arr:
        count += i // mid

    if count > m:
        start = mid + 1
    else:
        result = min(result, mid)
        end = mid - 1

print(result)
