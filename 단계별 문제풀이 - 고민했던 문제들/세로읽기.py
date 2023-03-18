# 글자수가 서로 다를수 있다는 조건을 구현하는 것이 핵심
import sys
array = []
for _ in range(5):
    s = sys.stdin.readline().strip()
    array.append(list(i for i in s))

l = []
max_length = len(array[0])
for i in array:
    if len(i) >= max_length:
        max_length = len(i)

for i in range(max_length):
    for j in array:
        if i > len(j) - 1:
            pass
        else:
            l.append(j[i])
for i in l:
    print(i, end='')
