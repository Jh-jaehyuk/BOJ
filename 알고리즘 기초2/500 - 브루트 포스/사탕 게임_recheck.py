import sys

# 입력 받기
n = int(sys.stdin.readline())
board = [list(sys.stdin.readline().strip()) for _ in range(n)]
max_count = 0

def count_candy():
    global max_count
    for i in range(n):
        count = 1
        for j in range(n - 1):
            if board[i][j] == board[i][j + 1]:
                count += 1
                max_count = max(max_count, count)
            else:
                count = 1

        count = 1
        for j in range(n - 1):
            if board[j][i] == board[j + 1][i]:
                count += 1
                max_count = max(max_count, count)
            else:
                count = 1

for i in range(n):
    for j in range(n):
        # 오른쪽으로 열 교환
        if j + 1 < n:
            board[i][j], board[i][j + 1] = board[i][j + 1], board[i][j]
            count_candy()
            board[i][j], board[i][j + 1] = board[i][j + 1], board[i][j]
        # 아래쪽으로 행 교환
        if i + 1 < n:
            board[i][j], board[i + 1][j] = board[i + 1][j], board[i][j]
            count_candy()
            board[i][j], board[i + 1][j] = board[i + 1][j], board[i][j]

print(max_count)
