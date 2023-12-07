import sys

n = int(sys.stdin.readline())
arr = [[] for _ in range(n * n + 1)]
board = [[0] * n for _ in range(n)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def count_prefer(x, y, tmp):
    count = 0

    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]

        if nx < 0 or nx >= n or ny < 0 or ny >= n:
            continue

        if board[nx][ny] in tmp:
            count += 1

    return count


def count_blank(x, y):
    count = 0

    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]

        if nx < 0 or nx >= n or ny < 0 or ny >= n:
            continue

        if board[nx][ny] == 0:
            count += 1

    return count


def find_seat(tmp):
    max_count = -1
    max_x, max_y = -1, -1
    seat_list = []

    for i in range(n):
        for j in range(n):
            if board[i][j] != 0:
                continue

            count = count_prefer(i, j, tmp)

            if count > max_count:
                max_count = count
                max_x, max_y = i, j
                seat_list = [(i, j)]

            elif count == max_count:
                seat_list.append((i, j))

    if len(seat_list) == 1:
        return max_x, max_y

    else:
        tmp_max = -1
        for x, y in seat_list:
            tmp_count = count_blank(x, y)

            if tmp_count > tmp_max:
                tmp_max = tmp_count
                max_x, max_y = x, y

        return max_x, max_y


for _ in range(n * n):
    idx, *tmp = map(int, sys.stdin.readline().split())
    arr[idx] = tmp
    x, y = find_seat(tmp)
    board[x][y] = idx

result = 0
for i in range(n):
    for j in range(n):
        val = count_prefer(i, j, arr[board[i][j]])

        if val == 0:
            continue
        result += 10 ** (val - 1)

print(result)
