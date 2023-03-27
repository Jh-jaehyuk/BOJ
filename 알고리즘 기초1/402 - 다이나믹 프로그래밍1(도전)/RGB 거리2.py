import sys

n = int(sys.stdin.readline())
# 앞서 계산된 결과를 저장하기 위한 DP 테이블 초기화
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
a = int(1e9)

# 다이나믹 프로그래밍 진행(보텀업)
for i in range(3):
    # 첫번째 집이 각각 r, g, b로 시작하는 경우
    d = [[a, a, a] for _ in range(n)]
    d[0][i] = arr[0][i]
    for j in range(1, n):
        d[j][0] = arr[j][0] + min(d[j - 1][1], d[j - 1][2])
        d[j][1] = arr[j][1] + min(d[j - 1][0], d[j - 1][2])
        d[j][2] = arr[j][2] + min(d[j - 1][0], d[j - 1][1])
    for k in range(3):
        # 첫번째 집과 n번째 집 색이 다른 경우만
        if i != k:
            a = min(a, d[-1][k])
print(a)
