import sys

a, b = map(int, sys.stdin.readline().split())
m = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
arr.reverse()
num = 0
answer = []

# a진법으로 나타낸 수를 10진법으로 변환
for i in range(m):
    num += arr[i] * (a ** i)

# 10진법으로 나타낸 수를 b로 나누어가면서 b진법으로 변환
while num != 0:
    answer.append(num % b) # num을 b로 나눈 나머지를 저장
    num //= b # num 을 b로 나눈 몫을 다시 입력

# 순서를 뒤집어 줘야하므로,
answer.reverse()
print(*answer)
