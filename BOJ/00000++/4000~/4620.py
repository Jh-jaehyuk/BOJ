import sys

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def solve(n):
    board = [list(sys.stdin.readline().rstrip()) for _ in range(n)]
    dp = [[0] * n for _ in range(n)]
    dp[0][0] = 1

    for i in range(n):
        for j in range(n):
            if i == n - 1 and j == n - 1:
                break

            tmp = int(board[i][j])

            if i + tmp < n:
                dp[i + tmp][j] += dp[i][j]

            if j + tmp < n:
                dp[i][j + tmp] += dp[i][j]

    print(dp[n - 1][n - 1])


while True:
    n = int(sys.stdin.readline())

    if n == -1:
        break

    solve(n)
