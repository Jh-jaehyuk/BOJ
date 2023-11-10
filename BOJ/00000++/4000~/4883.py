import sys


def solve(idx, n):
    graph = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
    dp = [[0] * 3 for _ in range(n)]

    dp[0][0] = int(1e9)
    dp[0][1] = graph[0][1]
    dp[0][2] = min(graph[0][1], graph[0][1] + graph[0][2])

    for i in range(1, n):
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + graph[i][0]
        dp[i][1] = min(min(dp[i - 1]), dp[i][0]) + graph[i][1]
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][2], dp[i][1]) + graph[i][2]

    print(f'{idx}. {dp[n - 1][1]}')


idx = 1
while True:
    n = int(sys.stdin.readline())

    if n == 0:
        break

    solve(idx, n)
    idx += 1
