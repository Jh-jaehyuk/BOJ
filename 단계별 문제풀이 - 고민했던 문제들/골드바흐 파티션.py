import sys

T = int(sys.stdin.readline())
# 리스트 초기화
prime = [True] * 1000001

for i in range(2, int(1000000 * 0.5) + 1):
    if prime[i]:
        # i 의 배수들은 소수가 아니므로 False로 변경
        for j in range(i * 2, 1000000, i):
            prime[j] = False

for _ in range(T):
    count = 0
    x = int(sys.stdin.readline())
    # 2에서 x의 절반까지
    for i in range(2, x // 2 + 1):
        # i와 x - i가 둘 다 소수라면 count 증가
        if prime[i] and prime[x - i]:
            count += 1
    print(count)
