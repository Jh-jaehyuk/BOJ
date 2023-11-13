n = int(input())
arr = list(map(int, input().split()))
check = [0] * 100001
result = 0

start, end = 0, 0
check[arr[end]] = 1

while start <= end:
    if end < n - 1:
        if check[arr[end + 1]]:
            if start == end:
                result += 1
                start += 1
                end += 1

            else:
                result += end - start + 1
                check[arr[start]] = 0
                start += 1

        else:
            end += 1
            check[arr[end]] = 1

    else:
        tmp = (end - start + 1) * (end - start + 2) // 2
        result += tmp
        break

print(result)
