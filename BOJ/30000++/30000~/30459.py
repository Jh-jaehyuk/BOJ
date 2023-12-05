import sys

N, M, R = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))
B = list(map(int, sys.stdin.readline().split()))

B.sort()
print("A")
arr = set()
for i in range(N):
    for j in range(N):
        if i == j:
            continue
        arr.add(abs(A[i] - A[j]))

Max = -1

for i in arr:
    left, right = 0, M - 1

    while left <= right:
        mid = (left + right) // 2
        tmp = i * B[mid] / 2

        if tmp > R:
            right = mid - 1

        else:
            left = mid + 1
            Max = max(Max, tmp)

print(Max)