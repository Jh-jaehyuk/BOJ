n = int(input())
arr = list(map(int, input().split()))
result = [arr[0]]


def binary_search(start, end, target):
    while start <= end:
        mid = (start + end) // 2

        if result[mid] == target:
            return mid

        elif result[mid] < target:
            start = mid + 1

        else:
            end = mid - 1
    return start


for i in range(1, n):
    if result[-1] < arr[i]:
        result.append(arr[i])

    else:
        result[binary_search(0, len(result), arr[i])] = arr[i]

print(len(result))