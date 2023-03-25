import sys

n = int(sys.stdin.readline())
# dp 테이블 초기화
d = [[0, 0] for _ in range(n + 1)]
# 초기값 설정
d[1] = [0, 1]

for i in range(2, n + 1):
    # 마지막 숫자가 0인 경우 뒤에 0, 1 이 올 수 있음
    d[i][0] = d[i - 1][0] + d[i - 1][1]
    # 마지막 숫자가 1인 경우 뒤에 0만 올 수 있음
    d[i][1] = d[i - 1][0]

print(sum(d[n]))
