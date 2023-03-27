import sys

n = int(sys.stdin.readline())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
d = [[0] * len(arr[i]) for i in range(len(arr))]
d[0][0] = arr[0][0]

if n == 1:
    print(arr[0][0])
    quit()

for i in range(n):
    for j in range(len(arr[i])):
        if j == 0:
            d[i][j] = d[i - 1][j] + arr[i][j]

        elif j == len(arr[i]) - 1:
            d[i][j] = d[i - 1][j - 1] + arr[i][j]

        else:
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + arr[i][j]

print(max(d[n - 1]))
