import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
d = [[0] * n for _ in range(2)]
d[0][0] = arr[0]

if n > 1:
    a = int(-1e9)
    for i in range(1, n):
        d[0][i] = max(d[0][i - 1] + arr[i], arr[i])
        d[1][i] = max(d[0][i - 1], d[1][i - 1] + arr[i])
        a = max(a, d[0][i], d[1][i])
    print(a)

else:
    print(d[0][0])
# 참고 : https://baby-ohgu.tistory.com/17
