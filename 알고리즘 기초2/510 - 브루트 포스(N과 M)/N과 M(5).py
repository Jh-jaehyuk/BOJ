import sys
from itertools import permutations

n, m = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
arr.sort()

answer = list(permutations(arr, m))
for i in answer:
    print(*i)
