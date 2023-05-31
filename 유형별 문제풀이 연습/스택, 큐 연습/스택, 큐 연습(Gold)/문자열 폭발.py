import sys

s = sys.stdin.readline().rstrip()
explosive = sys.stdin.readline().rstrip()
length = len(explosive)
stack = []
idx = 0

while idx < len(s):
    if ''.join(stack[-length:]) == explosive:
        for _ in range(length):
            stack.pop()
        idx -= 1

    else:
        stack.append(s[idx])
    idx += 1

if ''.join(stack[-length:]) == explosive:
    for _ in range(length):
        stack.pop()

if not stack:
    print('FRULA')
else:
    print(''.join(stack))
