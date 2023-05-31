import sys

n, m = map(int, sys.stdin.readline().split())
arr_a = [list(map(int, list(sys.stdin.readline().rstrip()))) for _ in range(n)]
arr_b = [list(map(int, list(sys.stdin.readline().rstrip()))) for _ in range(n)]

if n < 3 or m < 3:
    if arr_a != arr_b:
        print(-1)
        quit(0)
    else:
        print(0)
        quit(0)

count = 0
for i in range(n - 2):
    for j in range(m - 2):
        if arr_a[i][j] != arr_b[i][j]:
            count += 1
            for row in range(i, i + 3):
                for col in range(j, j + 3):
                    if arr_a[row][col] == 0:
                        arr_a[row][col] = 1
                    else:
                        arr_a[row][col] = 0

if arr_a == arr_b:
    print(count)
else:
    print(-1)
