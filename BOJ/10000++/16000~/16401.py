n, m = map(int, input().split())
L = sorted(list(map(int, input().split())))

start = 1
end = L[-1]
result = 0

while start <= end:
    mid = (start + end) // 2
    tmp = 0

    for i in L:
        if i >= mid:
            tmp += i // mid

    if tmp >= n:
        start = mid + 1
        result = max(result, mid)

    else:
        end = mid - 1

print(result)