from collections import Counter

n, c = map(int, input().split())
arr = list(map(int, input().split()))
count = Counter(arr)
d = dict()

for i in range(n):
    if arr[i] not in d:
        d[arr[i]] = i

arr.sort(key=lambda x: (-count[x], d[x]))
print(*arr)