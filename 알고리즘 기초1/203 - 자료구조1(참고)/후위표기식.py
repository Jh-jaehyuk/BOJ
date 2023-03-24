import sys

s = sys.stdin.readline().rstrip()
stack = []
priority = {'*': 2, '/': 2, '+': 1, '-': 1, '(': 0}

for i in '(' + s + ')':
    if 'A' <= i <= 'Z':
        print(i, end='')
    elif i == '(':
        stack.append(i)
    elif i == ')':
        while True:
            x = stack.pop()
            if x == '(':
                break
            print(x, end='')
    else:
        while stack[-1] != '(' and priority[i] <= priority[stack[-1]]:
            print(stack.pop(), end='')
        stack.append(i)
