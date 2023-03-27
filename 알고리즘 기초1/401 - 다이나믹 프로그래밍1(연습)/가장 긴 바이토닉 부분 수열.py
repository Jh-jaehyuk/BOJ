import sys

n = int(sys.stdin.readline())
arr1 = list(map(int, sys.stdin.readline().split()))
arr2 = list(reversed(arr1))

d1 = [1] * n
d2 = [1] * n

for i in range(n):
    for j in range(i):
        # 증가하는 부분 수열
        if arr1[i] > arr1[j]:
            d1[i] = max(d1[i], d1[j] + 1)
        # 감소하는 부분 수열
        if arr2[i] > arr2[j]:
            d2[i] = max(d2[i], d2[j] + 1)

d2.reverse()
l = []
for i in range(n):
    l.append(d1[i] + d2[i] - 1)
# 증가하는 부분 수열과 감소하는 부분 수열의 합이 최대가 되는 순간
print(max(l))
