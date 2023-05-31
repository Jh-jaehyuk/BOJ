n, k = map(int, input().split())

arr = [i for i in range(1, n + 1)]
idx = k - 1
result = '<'

for _ in range(n - 1):
    result += str(arr.pop(idx)) + ', '
    idx = (idx + k - 1) % len(arr)
result += str(arr.pop()) + '>'
print(result)
