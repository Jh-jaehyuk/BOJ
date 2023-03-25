import sys

n = int(sys.stdin.readline())
d = [[0] * 10 for _ in range(n + 1)]
d[1] = [0] + [1] * 9

for i in range(2, n + 1):
    for j in range(10):
        # 맨 뒷자리 숫자가 0이라면
        # 앞은 무조건 1임.
        if j == 0:
            d[i][j] = d[i - 1][1]
        # 맨 뒷자리 숫자가 9라면
        # 앞은 무조건 8임.
        elif j == 9:
            d[i][j] = d[i - 1][8]
        # 나머지는 그 숫자에서 -1, +1 해준 숫자가 올 수 있음.
        # j - 1, j + 1 이 그 의미임.
        else:
            d[i][j] = d[i - 1][j - 1] + d[i - 1][j + 1]

print(sum(d[n]) % int(1e9))
