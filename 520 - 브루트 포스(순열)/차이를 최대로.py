import sys
from itertools import permutations

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

arr2 = list(permutations(arr, n))
max_num = 0

for i in arr2:
    num = 0
    for j in range(1, len(i)):
        num += abs(i[j - 1] - i[j])
    max_num = max(max_num, num)
print(max_num)
