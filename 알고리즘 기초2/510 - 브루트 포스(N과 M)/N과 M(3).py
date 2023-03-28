import sys
from itertools import product

n, m = map(int, sys.stdin.readline().split())
arr = [i for i in range(1, n + 1)]
answer = list(product(arr, repeat=m))

for i in answer:
    print(*i)
