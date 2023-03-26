import sys

T = int(sys.stdin.readline())
# 앞서 계산된 결과를 저장하기 위한 DP 테이블 초기화
d = [0] * (int(1e6) + 1)

# 다이나믹 프로그래밍 진행(보텀업)
# 점화식 초기 값 계산
d[1] = 1 # n = 1일때
d[2] = 2 # n = 2일때
d[3] = 4 # n = 3일때

for _ in range(T):
    n = int(sys.stdin.readline())
    for i in range(4, n + 1):
        d[i] = (d[i - 1] % 1000000009 + d[i - 2] % 1000000009 + d[i - 3] % 1000000009)
    print(d[n] % 1000000009)
