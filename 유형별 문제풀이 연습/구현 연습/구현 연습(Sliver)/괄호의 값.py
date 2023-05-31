s = input()

stack = []
answer = 0
tmp = 1

for i in range(len(s)):
    if s[i] == '(':
        stack.append(s[i])
        tmp *= 2

    elif s[i] == '[':
        stack.append(s[i])
        tmp *= 3

    elif s[i] == ')':
        if not stack or stack[-1] == '[':
            answer = 0
            break
        if s[i - 1] == '(':
            answer += tmp
        stack.pop()
        tmp //= 2

    elif s[i] == ']':
        if not stack or stack[-1] == '(':
            answer = 0
            break
        if s[i - 1] == '[':
            answer += tmp
        stack.pop()
        tmp //= 3

if stack:
    print(0)
else:
    print(answer)
