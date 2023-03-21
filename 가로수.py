import sys

def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)

n = int(sys.stdin.readline())
array = []
l = []
for _ in range(n):
    array.append(int(sys.stdin.readline()))
for i in range(1, len(array)):
    l.append(array[i] - array[i - 1])

a = l[0]
for i in range(1, len(l)):
    a = gcd(a, l[i])
count = 0
for j in l:
    count += j // a - 1
print(count)
