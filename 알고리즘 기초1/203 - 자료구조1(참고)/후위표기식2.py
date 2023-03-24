import sys

n = int(sys.stdin.readline())
s = sys.stdin.readline().rstrip()

stack = []
num = [0] * n
for i in range(n):
    num[i] = int(sys.stdin.readline())

for j in s:
    if 'A' <= j <= 'Z':
        stack.append(num[ord(j) - ord('A')])

    else:
        s2 = stack.pop()
        s1 = stack.pop()

        if j == '+':
            stack.append(s1 + s2)
        elif j == '-':
            stack.append(s1 - s2)
        elif j == '*':
            stack.append(s1 * s2)
        elif j == '/':
            stack.append(s1 / s2)

print('%.2f' % stack[0])
