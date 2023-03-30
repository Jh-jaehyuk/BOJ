import sys

n = int(sys.stdin.readline())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

# 여기서 DP 테이블은 i번째날까지 일했을 때 얻는 최대 수익
d = [0] * (n + 1)

for i in range(n):
    for j in range(i + arr[i][0], n + 1):
        if d[j] < d[i] + arr[i][1]:
            d[j] = d[i] + arr[i][1]

print(d[n])
