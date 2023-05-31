n = int(input())
arr = list(map(int, input().split()))
arr.sort()
result = [0] * n
result[0] = arr[0]

for i in range(1, n):
    result[i] = result[i - 1] + arr[i]

print(sum(result))
