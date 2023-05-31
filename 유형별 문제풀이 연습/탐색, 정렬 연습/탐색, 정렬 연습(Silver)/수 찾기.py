n = int(input())
arr1 = list(map(int, input().split()))
m = int(input())
arr2 = list(map(int, input().split()))

arr1.sort()

for i in arr2:
    left, right = 0, n - 1
    flag = False
    while left <= right:
        mid = (left + right) // 2

        if arr1[mid] == i:
            print(1)
            flag = True
            break

        elif arr1[mid] < i:
            left = mid + 1

        else:
            right = mid - 1
    if not flag:
        print(0)
