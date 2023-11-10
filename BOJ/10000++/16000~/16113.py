n = int(input())
s = input()

length = n // 5
board = [[''] * length for _ in range(5)]

for i in range(len(s)):
    board[i // length][i % length] = s[i]

visited = [False] * length


def check(x, y):
    row = 0
    col = 0

    for i in range(5):
        if board[i][y] == '#':
            row += 1

    for j in range(3):
        if y + j >= length:
            return '1'
        if board[x][y + j] == '#':
            col += 1

    if row == 5:
        if col == 1:
            return '1'

        else:
            if board[x + 1][y + 2] == '#':
                if board[x + 2][y + 1] == '#':
                    return '8'
                else:
                    return '0'
            else:
                return '6'

    if row == 4 and col == 3:
        if board[x + 1][y] == '#':
            if board[x + 3][y] == '#':
                return '9'
            return '5'
        else:
            return '2'

    if row == 3:
        if col == 3:
            return '3'

        else:
            return '4'

    if row == 1 and col == 3:
        return '7'


result = ''
for i in range(length):
    if board[0][i] == '#' and not visited[i]:
        visited[i] = True
        tmp = check(0, i)
        if tmp == '1':
            if i != length - 1:
                visited[i + 1] = True
        else:
            visited[i + 1] = True
            visited[i + 2] = True
        result += tmp

print(result)