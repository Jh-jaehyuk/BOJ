import sys

while True:
    s = sys.stdin.readline().rstrip()

    if s == '.':
        break

    stack = []
    flag = True

    for i in s:
        if not stack:
            if i == ')' or i == ']':
                flag = False
                continue
            elif i == '(' or i == '[':
                stack.append(i)

        else:
            if i == ')':
                if stack[-1] == '(':
                    stack.pop()
                else:
                    flag = False
                    continue

            elif i == ']':
                if stack[-1] == '[':
                    stack.pop()
                else:
                    flag = False
                    continue

            elif i == '(' or i == '[':
                stack.append(i)
    if stack:
        flag = False

    if flag:
        print('yes')
    else:
        print('no')
