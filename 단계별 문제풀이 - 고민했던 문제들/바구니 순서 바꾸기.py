import sys
n, m = map(int, input().split())
array = [i for i in range(1, n + 1)]
for _ in range(m):
    i, j, k = map(int, sys.stdin.readline().split())
    array = array[:(i - 1)] + array[(k - 1):j] + array[(i - 1):(k - 1)] + array[j:]
    # 리스트 슬라이싱을 적절하게 이용할 것.
for i in array:
    print(i, end=' ')
