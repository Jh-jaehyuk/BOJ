import sys
from collections import deque

T = int(sys.stdin.readline())

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def BFS(x, y):
    global result
    visited = [[False] * (m + 2) for _ in range(n + 2)]
    visited[x][y] = True
    queue = deque()
    queue.append((x, y))

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if nx < 0 or nx >= n + 2 or ny < 0 or ny >= m + 2:
                continue

            if visited[nx][ny]:
                continue

            if board[nx][ny] == '*':
                continue

            if board[nx][ny].isalpha():
                if board[nx][ny].islower():
                    check[ord(board[nx][ny]) - ord('a')] = True
                    board[nx][ny] = '.'
                    queue.append((nx, ny))

                else:
                    if check[ord(board[nx][ny]) - ord('A')]:
                        visited[nx][ny] = True
                        board[nx][ny] = '.'
                        queue.append((nx, ny))
                    else:
                        lock[ord(board[nx][ny]) - ord('A')].append((nx, ny))

            else:
                if board[nx][ny] == '.':
                    visited[nx][ny] = True
                    queue.append((nx, ny))

                else:
                    result += 1
                    visited[nx][ny] = True
                    board[nx][ny] = '.'
                    queue.append((nx, ny))


for t in range(T):
    n, m = map(int, sys.stdin.readline().rstrip().split())
    board = [['.'] * (m + 2) for _ in range(n + 2)]
    result = 0

    for i in range(1, n + 1):
        tmp = sys.stdin.readline().rstrip()
        for j in range(1, m + 1):
            board[i][j] = tmp[j - 1]

    check = [False] * 26
    lock = [deque() for _ in range(26)]
    key = sys.stdin.readline().rstrip()

    if key != '0':
        for i in key:
            check[ord(i) - ord('a')] = True

    BFS(0, 0)

    while True:
        flag = False
        for i in range(26):
            if lock[i] and check[i]:
                flag = True
                x, y = lock[i].popleft()
                BFS(x, y)
                break

        if not flag:
            break

    print(result)