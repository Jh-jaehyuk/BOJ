n = int(input())
arr = list(map(int, input().split())) + [0] * 2

total = 0

for i in range(n):
    total += arr[i]

dp = [0] * (n + 2)

for i in range(2, n + 2):
    if i == 2:
        dp[i] = max(dp[i - 1], arr[i - 2] + arr[i - 1] + arr[i])
    else:
        dp[i] = max(dp[i - 1], dp[i - 3] + arr[i - 2] + arr[i - 1] + arr[i])

print(total + dp[n + 1])
