# 처음엔 커서를 기준으로 슬라이싱으로 처리했는데 >> 시간초과
# 그 다음으로 append 와 pop만 이용하여 통과
import sys

s = list(i for i in sys.stdin.readline().rstrip())
cursor = len(s)
m = int(sys.stdin.readline())
# 커서를 기준으로 왼쪽 오른쪽 문자열을 나눔.
l_list = s
r_list = []

for _ in range(m):
    a = list(sys.stdin.readline().rstrip().split())

    if 'L' in a and l_list:
        r_list.append(l_list.pop())

    elif 'D' in a and r_list:
        l_list.append(r_list.pop())

    elif 'B' in a and l_list:
        l_list.pop()

    elif 'P' in a:
        l_list.append(a[1])

r_list.reverse()
print(''.join(l_list) + ''.join(r_list))
