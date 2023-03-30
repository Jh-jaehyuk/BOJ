import sys
from itertools import permutations

n = int(sys.stdin.readline())
arr = [i for i in range(1, n + 1)]
arr2 = list(permutations(arr, n))
for i in arr2:
    print(*i)
