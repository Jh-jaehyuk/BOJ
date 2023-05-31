import sys

T, W = map(int, sys.stdin.readline().split())
fruits = []
result = 0

for _ in range(T):
    fruits.append(int(sys.stdin.readline()))

d = [[0] * (W + 1) for _ in range(T + 1)]

for i in range(1, T + 1):
    if fruits[i - 1] == 1:
        d[i][0] = d[i - 1][0] + 1
    else:
        d[i][0] = d[i - 1][0]

    for j in range(1, W + 1):
        # j % 2 가 짝수라면 1번 위치,
        # 홀수라면 2번 위치에 있는 것
        if fruits[i - 1] == 2 and j % 2 == 1:
            # 자두가 2번 위치에 떨어지고 2번 위치에 있는 경우 개수 + 1
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + 1
        elif fruits[i - 1] == 1 and j % 2 == 0:
            # 자두가 1번 위치에 떨어지고 1번 위치에 있는 경우 개수 + 1
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + 1
        else:
            # 나머지는 개수 변화 없음
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j])

print(max(d[T]))
