import sys
from collections import defaultdict


def convert_time(s):
    h, m = map(int, s.split(':'))
    return h * 60 + m


s, e, q = map(convert_time, sys.stdin.readline().rstrip().split())
d = defaultdict(int)


while True:
    tmp = sys.stdin.readline().rstrip()
    if tmp == '':
        break

    t, name = tmp.split()
    t = convert_time(t)

    if t <= s and d[name] == 0:
        d[name] = 1

    if e <= t <= q and d[name] == 1:
        d[name] = 2

print(list(d.values()).count(2))