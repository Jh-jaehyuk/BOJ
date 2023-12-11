n = int(input())
MOD = int(1e9)

dp = [[[0] * (1 << 10) for _ in range(10)] for _ in range(n + 1)]

for i in range(1, 10):
    dp[1][i][1 << i] = 1

for i in range(1, n):
    for j in range(10):
        for k in range(1 << 10):
            if j == 0:
                dp[i + 1][j + 1][k | 1 << (j + 1)] += dp[i][j][k]
                dp[i + 1][j + 1][k | 1 << (j + 1)] %= MOD

            elif j == 9:
                dp[i + 1][j - 1][k | 1 << (j - 1)] += dp[i][j][k]
                dp[i + 1][j - 1][k | 1 << (j - 1)] %= MOD

            else:
                dp[i + 1][j + 1][k | 1 << (j + 1)] += dp[i][j][k]
                dp[i + 1][j + 1][k | 1 << (j + 1)] %= MOD
                dp[i + 1][j - 1][k | 1 << (j - 1)] += dp[i][j][k]
                dp[i + 1][j - 1][k | 1 << (j - 1)] %= MOD

result = 0
for i in range(10):
    result += dp[n][i][(1 << 10) - 1]
    result %= MOD

print(result)