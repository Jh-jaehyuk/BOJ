from collections import deque

s, t = map(int, input().split())

if s == t:
    print(0)
    quit(0)

queue = deque()
queue.append((s, ''))
check = set()
check.add(s)

while queue:
    n, tmp = queue.popleft()

    if n == t:
        print(tmp)
        quit(0)

    for operator in ['*', '+', '-', '/']:
        if operator == '*':
            next_n = n * n
        elif operator == '+':
            next_n = 2 * n
        elif operator == '-':
            next_n = 0
        else:
            next_n = 1

        if next_n not in check and next_n <= max(s, t):
            queue.append((next_n, tmp + operator))
            check.add(next_n)

print(-1)
