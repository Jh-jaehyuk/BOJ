import sys

n = int(sys.stdin.readline())
# list에서 찾는 시간복잡도는 O(N)
# set에서 찾는 시간복잡도는 O(1)
arr1 = set(map(int, sys.stdin.readline().split()))
m = int(sys.stdin.readline())
arr2 = list(map(int, sys.stdin.readline().split()))

for i in arr2:
    if i in arr1:
        print(1, end=' ')
    else:
        print(0, end=' ')
