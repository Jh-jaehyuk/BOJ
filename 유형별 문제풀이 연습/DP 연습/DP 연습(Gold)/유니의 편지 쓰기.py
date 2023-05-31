import sys

n = int(sys.stdin.readline())


def change(s):
    s = s.split('-')
    y, m = map(int, s)
    y *= 12
    return y + m


min_val = change('2000-01')
max_val = change('9999-12')

d = [0] * (max_val + 2)
for _ in range(n):
    s = sys.stdin.readline().split()
    start, end = map(change, s)
    d[start] += 1
    d[end + 1] -= 1

max_num = 0
result = 0
for i in range(min_val, max_val + 1):
    d[i] += d[i - 1]
    if d[i] > max_num:
        max_num = d[i]
        result = i

yy, mm = divmod(result, 12)
if mm == 0:
    mm = 12
    yy -= 1
print(f'{yy}-{mm:02}')
