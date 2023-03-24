import sys

n, b = sys.stdin.readline().rstrip().split()
b = int(b)
# int는 b진법으로 표현된 숫자 n을 10진법으로 변환해줌.
print(int(n, b))
