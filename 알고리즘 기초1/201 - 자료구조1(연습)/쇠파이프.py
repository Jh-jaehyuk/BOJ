import sys

s = sys.stdin.readline().rstrip()
pipe = 0
count = 0

for i in range(len(s)):
    # 문자열을 하나씩 지나가면서
    if s[i] == '(':
        if s[i + 1] == ')':
            # ( 뒤에 바로 ) 가 온다면 레이저.
            if pipe != 0:
                # 파이프 개수만큼 총 개수에 추가
                count += pipe
        else:
            # ( 뒤에 ( 가 오는 경우 파이프가 새로 시작되는 것
            pipe += 1 # 파이프를 하나 증가

    elif s[i] == ')':
        if s[i - 1] != '(':
            # ) 앞에 ( 오지 않으면 파이프가 끝나는 부분임.
            count += 1 # 총 개수를 하나 증가시키고
            pipe -= 1 # 파이프 개수를 하나 감소시킴.

print(count)
