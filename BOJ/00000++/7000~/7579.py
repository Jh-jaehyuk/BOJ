n, m = map(int, input().split())
A = [0] + list(map(int, input().split()))
C = [0] + list(map(int, input().split()))
total = sum(C)

dp = [0] * (total + 1)

for i in range(1, n + 1):
    for j in range(total, C[i] - 1, -1):
        dp[j] = max(dp[j], dp[j - C[i]] + A[i])

for i in range(total + 1):
    if dp[i] >= m:
        print(i)
        break
