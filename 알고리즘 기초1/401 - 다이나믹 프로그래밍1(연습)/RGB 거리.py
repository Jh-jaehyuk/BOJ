import sys

n = int(sys.stdin.readline())
# 앞서 계산된 결과를 저장하기 위한 DP 테이블 초기화
d = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

# 다이나믹 프로그래밍 진행(보텀업)
for i in range(1, n):
    d[i][0] = min(d[i - 1][1], d[i - 1][2]) + d[i][0]
    d[i][1] = min(d[i - 1][0], d[i - 1][2]) + d[i][1]
    d[i][2] = min(d[i - 1][0], d[i - 1][1]) + d[i][2]

print(min(d[n - 1]))
