import sys

n = int(sys.stdin.readline())
arr = [list(map(lambda x: ord(x) - 65, sys.stdin.readline().rstrip())) for _ in range(n)]
l = [0] * 26

for i in range(n):
    j = 0
    for word in arr[i][::-1]:
        l[word] += (10 ** j)
        j += 1

l.sort(reverse=True)
a = 0
b = 9

for i in range(26):
    if l[i] == 0:
        break
    a += (b * l[i])
    b -= 1

print(a)
