import sys

n = int(sys.stdin.readline())
# 앞서 계산된 결과를 저장하기 위한 DP 테이블 초기화
d = [0] * 1001
# 카드 저장
arr = [0] + list(map(int, sys.stdin.readline().split()))

for i in range(1, n + 1):
    for j in range(1, i + 1):
        # d[i] 는 i 장의 카드를 구매했을 때의 최대 가격
        # arr[j] 는 j 장이 있는 카드팩 하나만 구매하는 경우
        d[i] = max(d[i], d[i - j] + arr[j])

print(d[n])
