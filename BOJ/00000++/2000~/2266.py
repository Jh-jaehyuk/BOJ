n, k = map(int, input().split())
dp = [[0] * 501 for _ in range(501)]
INF = int(1e9)

for i in range(1, n + 1):
    dp[i][1] = i

for i in range(1, n + 1):
    for j in range(2, k + 1):
        dp[i][j] = INF
        for l in range(1, i + 1):
            dp[i][j] = min(dp[i][j], max(dp[l - 1][j - 1], dp[i - l][j]) + 1)

print(dp[n][k])
