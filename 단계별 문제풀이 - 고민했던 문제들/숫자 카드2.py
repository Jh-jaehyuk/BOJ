import sys
from bisect import bisect_left, bisect_right

def count_by_range(array, left_value, right_value):
    left_index = bisect_left(array, left_value)
    right_index = bisect_right(array, right_value)
    return right_index - left_index

n = int(sys.stdin.readline())
arr1 = list(map(int, sys.stdin.readline().split()))
arr1.sort() # 이진탐색을 위해서 정렬 필요함.
m = int(sys.stdin.readline())
arr2 = list(map(int, sys.stdin.readline().split()))

for i in arr2:
    print(count_by_range(arr1, i, i), end=' ')
