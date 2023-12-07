n = int(input())
s = input()

num = []
op = []

for i in range(n):
    if i % 2 == 0:
        num.append(int(s[i]))
    else:
        op.append(s[i])

result = -int(1e9)


def calculate(num1, num2, operator):
    if operator == '+':
        return num1 + num2

    elif operator == '-':
        return num1 - num2

    else:
        return num1 * num2


def solve(total, idx):
    global result

    if idx == n // 2:
        result = max(result, total)
        return

    solve(calculate(total, num[idx + 1], op[idx]), idx + 1)

    if idx < n // 2 - 1:
        solve(calculate(total, calculate(num[idx + 1], num[idx + 2], op[idx + 1]), op[idx]), idx + 2)


solve(num[0], 0)
print(result)
