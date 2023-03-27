import sys
from itertools import combinations

arr = []
for _ in range(9):
    arr.append(int(sys.stdin.readline()))

arr2 = combinations(arr, 7)
for i in arr2:
    if sum(i) == 100:
        x = i
        break

x = sorted(x)
for i in x:
    print(i)
