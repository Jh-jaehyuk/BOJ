import sys
n = int(input())
count = 0
for _ in range(n):
    s = sys.stdin.readline().strip()
    d = []
    for i in s:
        if i not in d:
            d.append(i)
        if i in d and i != d[-1]:
            count -= 1
            break
    count += 1

if count <= 0:
    count = 0
print(count)
