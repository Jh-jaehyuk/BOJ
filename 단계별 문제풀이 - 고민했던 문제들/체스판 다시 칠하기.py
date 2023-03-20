import sys
n, m = map(int, sys.stdin.readline().split())
board = [sys.stdin.readline().rstrip() for _ in range(n)]

target1 = ['BWBWBWBW', 'WBWBWBWB'] * 4
target2 = target1[::-1]

answer = 64
for i in range(n - 7):
    for j in range(m - 7):
        count1 = count2 = 0
        for k in range(8):
            for l in range(8):
                count1 += (target1[k][l] != board[i + k][j + l])
            for l in range(8):
                count2 += (target2[k][l] != board[i + k][j + l])
        answer = min(answer, count1, count2)
print(answer)
