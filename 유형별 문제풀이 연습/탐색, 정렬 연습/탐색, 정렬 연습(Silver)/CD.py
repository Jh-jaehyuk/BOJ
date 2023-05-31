import sys

while True:
    n, m = map(int, sys.stdin.readline().split())

    if n == m == 0:
        break

    arr1 = [int(sys.stdin.readline()) for _ in range(n)]
    arr2 = [int(sys.stdin.readline()) for _ in range(m)]
    count = 0

    for x in arr1:
        left, right = 0, m - 1

        while left <= right:
            mid = (left + right) // 2

            if arr2[mid] == x:
                count += 1
                break

            elif arr2[mid] > x:
                right = mid - 1

            else:
                left = mid + 1

    print(count)
