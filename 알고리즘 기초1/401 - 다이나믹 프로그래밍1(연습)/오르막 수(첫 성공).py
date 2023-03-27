import sys

n = int(sys.stdin.readline())

d = [[0] * 10 for _ in range(n + 1)]
d[1] = [1] * 10

for i in range(2, n + 1):
    # 맨 마지막 숫자를 j 라고 함.
    for j in range(10):
        # 그럴 경우 그 앞에 올수 있는 수는 0 ~ j 까지.
        for k in range(j + 1):
            # j가 0이면 그 앞에도 0만 올 수 있음.
            if j == 0:
                d[i][j] = d[i - 1][0]
            else:
                d[i][j] += d[i - 1][k]

print(sum(d[n]) % 10007)
