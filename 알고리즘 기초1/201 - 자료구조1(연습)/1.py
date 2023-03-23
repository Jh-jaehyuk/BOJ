import sys

s = list(sys.stdin.readline().rstrip())

i = 0
start = 0

while i < len(s):
    # 문자열이 열린 괄호라면
    if s[i] == '<':
        i += 1
        # 문자열이 닫힌 괄호가 될 때까지 인덱스 증가
        while s[i] != '>':
            i += 1
        # 닫힌 괄호가 되면 인덱스 하나 증가
        i += 1
    # 숫자나 알파벳이면
    elif s[i].isalnum():
        start = i
        while i < len(s) and s[i].isalnum():
            i += 1
        tmp = s[start:i]
        tmp.reverse()
        s[start:i] = tmp
    # 공백 문자
    else:
        i += 1

print(''.join(s))


