import sys

n = int(sys.stdin.readline())
board = [[0] * (n + 1)]

for _ in range(n):
    board.append([0] + list(map(int, sys.stdin.readline().split())))


def solve(x, y, d1, d2):
    tmp = [0] * 5
    check = [[False] * (n + 1) for _ in range(n + 1)]

    for i in range(d1 + 1):
        check[x + i][y - i] = True
        check[x + d2 + i][y + d2 - i] = True

    for i in range(d2 + 1):
        check[x + i][y + i] = True
        check[x + d1 + i][y - d1 + i] = True

    for i in range(x + 1, x + d1 + d2):
        flag = False

        for j in range(1, n + 1):
            if check[i][j]:
                flag = not flag

            if flag:
                check[i][j] = True

    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if i < x + d1 and j <= y and not check[i][j]:
                tmp[0] += board[i][j]

            elif i <= x + d2 and y < j and not check[i][j]:
                tmp[1] += board[i][j]

            elif x + d1 <= i and j < y - d1 + d2 and not check[i][j]:
                tmp[2] += board[i][j]

            elif x + d2 < i and y - d1 + d2 <= j and not check[i][j]:
                tmp[3] += board[i][j]

            else:
                tmp[4] += board[i][j]

    return max(tmp) - min(tmp)


result = int(1e9)
for x in range(1, n + 1):
    for y in range(1, n + 1):
        for d1 in range(1, n + 1):
            for d2 in range(1, n + 1):
                if 1 <= x < x + d1 + d2 <= n and 1 <= y - d1 < y < y + d2 <= n:
                    result = min(result, solve(x, y, d1, d2))


print(result)
