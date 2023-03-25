import sys

n = int(sys.stdin.readline())
# 앞서 계산된 결과를 저장하기 위한 DP 테이블 초기화
d = [0] * 1001

# 다이나믹 프로그래밍 진행(보텀업)
# 점화식 초기 값 계산
d[1] = 1 # 2 * 1 타일
d[2] = 3 # 2 * 2 타일
for i in range(3, n + 1):
    d[i] = (d[i - 1] + 2 * d[i - 2]) % 10007

print(d[n])
