import sys
from itertools import combinations_with_replacement as cwr

n, m = map(int, sys.stdin.readline().split())
arr = [i for i in range(1, n + 1)]
answer = list(cwr(arr, m))

for i in answer:
    print(*i)
