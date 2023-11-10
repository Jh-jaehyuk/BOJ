n = int(input())
abs_n = abs(n)
MOD = int(1e9)
dp = [0] * 1000001
dp[1] = 1

for i in range(2, abs_n + 1):
    dp[i] = (dp[i - 1] + dp[i - 2]) % MOD

if n < 0:
    if n % 2 == 0:
        print(-1)
    else:
        print(1)

elif n > 0:
    print(1)

else:
    print(0)

print(dp[abs_n])
