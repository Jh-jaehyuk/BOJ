import sys

s = sys.stdin.readline().rstrip()
# int(s, 2) 는 2진수 s를 10진수로 변환
# oct(10진수)는 10진수를 8진수로 변환
# 끝에 [2:] 는 8진수로 나온 값에서 8진수 접두어 '0o' 를 제거하기 위함.
print(oct(int(s, 2))[2:])
