import sys

n = int(sys.stdin.readline())
answer = []
if n == 0:
    print(0)

else:
    while n:
        # 숫자가 -2로 나누어 떨어지지 않으면,
        if n % -2 != 0:
            # 나머지는 1이고
            answer.append('1')
            # 남은 숫자는 -2로 나누고 1을 더해줌.
            n //= -2
            n += 1
        else:
            # -2 로 나누어 떨어지면 나머지는 0이고,
            # 남은 숫자는 -2로 나누어 줌.
            answer.append('0')
            n //= -2

# 순서가 반대로 되어있으므로 순서를 뒤집어서 출력.
for i in answer[::-1]:
    print(i, end='')
