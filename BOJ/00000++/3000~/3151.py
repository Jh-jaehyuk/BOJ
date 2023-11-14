n = int(input())
A = sorted(list(map(int, input().split())))
result = 0

for i in range(n - 2):
    val = -A[i]
    start, end = i + 1, n - 1
    idx = n

    while start <= end:
        tmp = A[start] + A[end]

        if tmp < val:
            start += 1

        elif tmp > val:
            end -= 1

        else:
            if A[start] == A[end]:
                result += end - start

            else:
                if idx > end:
                    idx = end

                    while idx >= 0 and A[idx - 1] == A[end]:
                        idx -= 1

                result += end - idx + 1

            start += 1

print(result)