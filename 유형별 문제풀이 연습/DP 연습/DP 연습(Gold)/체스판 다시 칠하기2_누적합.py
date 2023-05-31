import sys

n, m, k = map(int, sys.stdin.readline().split())
board = [sys.stdin.readline().rstrip() for _ in range(n)]


def check(color):
    sum_arr = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(n):
        for j in range(m):
            if (i + j) % 2 == 0:
                val = board[i][j] != color
            else:
                val = board[i][j] == color
            sum_arr[i + 1][j + 1] = sum_arr[i][j + 1] + sum_arr[i + 1][j] - sum_arr[i][j] + val

    count = int(1e9)
    for i in range(1, n - k + 2):
        for j in range(1, m - k + 2):
            count = min(count, sum_arr[i + k - 1][j + k - 1] - sum_arr[i + k - 1][j - 1] - sum_arr[i - 1][j + k - 1] + sum_arr[i - 1][j - 1])

    return count


print(min(check('B'), check('W')))

