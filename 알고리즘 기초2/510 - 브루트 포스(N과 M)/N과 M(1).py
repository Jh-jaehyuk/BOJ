import sys
from itertools import permutations

n, m = map(int, sys.stdin.readline().split())
arr = [i for i in range(1, n + 1)]
answer = list(permutations(arr, m))
for i in answer:
    print(*i)
