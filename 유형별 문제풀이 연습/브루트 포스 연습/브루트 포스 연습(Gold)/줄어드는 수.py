from itertools import combinations

n = int(input())
arr = []

for i in range(1, 11):
    for c in combinations(range(0, 10), i):
        c = list(c)
        c.sort(reverse=True)
        arr.append(int(''.join(map(str, c))))

arr.sort()

if n < len(arr) + 1:
    print(arr[n - 1])
else:
    print(-1)
