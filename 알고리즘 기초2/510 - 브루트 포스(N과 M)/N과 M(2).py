import sys
from itertools import combinations

n, m = map(int, sys.stdin.readline().split())
arr = [i for i in range(1, n + 1)]

answer = list(combinations(arr, m))
for i in answer:
    print(*i)
