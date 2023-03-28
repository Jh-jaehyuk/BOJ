import sys

n, m = map(int, sys.stdin.readline().split())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
max_num = 0

# 첫번째
for i in range(n):
    for j in range(m - 3):
        x = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3]
        max_num = max(max_num, x)

for i in range(n - 3):
    for j in range(m):
        x = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j]
        max_num = max(max_num, x)

# 두번째
# 대칭 x
for i in range(n - 2):
    for j in range(m - 1):
        x = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1]
        y = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1]
        max_num = max(max_num, x, y)

for i in range(n - 1):
    for j in range(m - 2):
        x = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i][j + 2]
        y = arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2] + arr[i][j + 2]
        max_num = max(max_num, x, y)

# 대칭 o
for i in range(n - 2):
    for j in range(m - 1):
        x = arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1] + arr[i + 2][j]
        y = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 2][j]
        max_num = max(max_num, x, y)

for i in range(n - 1):
    for j in range(m - 2):
        x = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2]
        y = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2]
        max_num = max(max_num, x, y)

# 세번째
# 대칭 x
for i in range(n - 2):
    for j in range(m - 1):
        x = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1]
        max_num = max(max_num, x)

for i in range(n - 1):
    for j in range(m - 2):
        x = arr[i + 1][j] + arr[i + 1][j + 1] + arr[i][j + 1] + arr[i][j + 2]
        max_num = max(max_num, x)

# 대칭 o
for i in range(n - 2):
    for j in range(m - 1):
        x = arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j]
        max_num = max(max_num, x)

for i in range(n - 1):
    for j in range(m - 2):
        x= arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2]
        max_num = max(max_num, x)

# 네번째
for i in range(n - 1):
    for j in range(m - 2):
        x = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i][j + 2]
        y = arr[i + 1][j] + arr[i + 1][j + 1] + arr[i][j + 1] + arr[i + 1][j + 2]
        max_num = max(max_num, x, y)

for i in range(n - 2):
    for j in range(m - 1):
        x = arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1]
        y = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1]
        max_num = max(max_num, x, y)

# 다섯번째
for i in range(n - 1):
    for j in range(m - 1):
        x = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1]
        max_num = max(max_num, x)

print(max_num)
