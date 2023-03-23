import sys

n = int(sys.stdin.readline())
arr = []
stack = []
i = 0

for _ in range(n):
    num = int(sys.stdin.readline())
    # 스택 마지막 숫자가 입력받은 값보다 작으면
    # 입력받은 값과 같아질 때까지 append
    while i < num:
        i += 1
        stack.append(i)
        arr.append('+')
    # 스택 마지막 숫자가 입력받은 값과 같으면
    # 스택 마지막 숫자를 제거함.
    if stack[-1] == num:
        stack.pop()
        arr.append('-')
    # 스택 마지막 숫자가 입력받은 값보다 크면
    # 문제 해결이 불가능하므로 NO
    else:
        print('NO')
        quit()

for i in arr:
    print(i)
