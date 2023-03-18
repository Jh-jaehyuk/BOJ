import sys
n, m = map(int, input().split())
array_a = []
array_b = []

for _ in range(n):
    array_a.append(list(map(int, sys.stdin.readline().split())))

for _ in range(n):
    array_b.append(list(map(int, sys.stdin.readline().split())))

answer = [[0] * m for _ in range(n)]
for i in range(n):
    for j in range(m):
        answer[i][j] = array_a[i][j] + array_b[i][j]

for i in answer:
    for j in i:
        print(j, end=' ')
    print('')
