import sys

T = int(sys.stdin.readline())

for _ in range(T):
    n = int(sys.stdin.readline())
    arr = [list(map(int, sys.stdin.readline().split())) for _ in range(2)]

    if n > 1:
        arr[0][1] += arr[1][0]
        arr[1][1] += arr[0][0]

    for i in range(2, n):
        # n 번째 윗 점수가 선택되는 경우는
        # n - 1, n - 2 번째 아랫 점수를 선택하는 경우임.
        arr[0][i] += max(arr[1][i - 1], arr[1][i - 2])
        arr[1][i] += max(arr[0][i - 1], arr[0][i - 2])

    print(max(arr[0][n - 1], arr[1][n - 1]))
# 참고 : https://sungmin-joo.tistory.com/42
