import sys

n = int(sys.stdin.readline())
pos = []
neg = []
s = 0

for _ in range(n):
    x = int(sys.stdin.readline())
    if x == 1:
        s += 1
    elif x > 0:
        pos.append(x)
    else:
        neg.append(x)

pos.sort()
neg.sort(reverse=True)

while pos:
    if len(pos) == 1:
        s += pos.pop()
    else:
        s += pos.pop() * pos.pop()

while neg:
    if len(neg) == 1:
        s += neg.pop()
    else:
        s += neg.pop() * neg.pop()

print(s)
