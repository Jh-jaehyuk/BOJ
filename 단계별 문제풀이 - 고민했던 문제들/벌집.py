import sys

n = int(sys.stdin.readline())
x = ((n-1)/3)**(1/2)
print(round(x)+1)

# 참고 : https://www.acmicpc.net/board/view/99363
# 계차수열의 성질 이용
