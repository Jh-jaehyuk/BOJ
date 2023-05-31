from itertools import combinations

n = int(input())
arr = []

for i in range(1, 11):
    for c in combinations(range(0, 10), i):
        c = list(c)
        c.sort(reverse=True)
        arr.append(int(''.join(map(str, c))))

arr.sort()

if n < len(arr):
    print(arr[n])
else:
    print(-1)
