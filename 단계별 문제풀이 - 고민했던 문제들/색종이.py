# 색종이와 도화지를 좌표로 구현하여 색종이가 있는 부분을
# 0에서 1로 변경. 이미 1 인 부분은 따로 변하지 않으므로
# 겹치는 문제도 바로 해결가능함.
import sys
# 100 * 100 크기 도화지를 행렬로 설정
array = [[0] * 100 for _ in range(100)]
n = int(sys.stdin.readline().rstrip())
for _ in range(n):
    a, b = map(int, sys.stdin.readline().split())
    # 색종이 크기만큼 도화지 행렬의 [0] 을 [1]로 변경
    for i in range(a, a + 10):
        for j in range(b, b + 10):
            array[i][j] = 1
count = 0
for i in range(100):
    for j in range(100):
        # 도화지 행렬에서 [1]의 개수를 세어줌.
        if array[i][j] == 1:
            count += 1
print(count)
