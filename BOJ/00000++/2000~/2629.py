n = int(input())
A = list(map(int, input().split()))
m = int(input())
B = list(map(int, input().split()))

dp = [[0] * 40001 for _ in range(31)]
for i in range(n):
    dp[i][A[i]] = 1
    
    if not i:
        continue
    
    for j in range(40001):
        if dp[i - 1][j]:
            dp[i][j] = 1
            if j + A[i] < 40001:
                dp[i][j + A[i]] = 1
            dp[i][abs(j - A[i])] = 1

for i in range(m):
    if dp[n - 1][B[i]]:
        print("Y", end=" ")
    else:
        print("N", end=" ")
