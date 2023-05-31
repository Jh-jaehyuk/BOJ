s = input().split('-')

num = []

for i in s:
    x = 0
    tmp = i.split('+')
    for j in tmp:
        x += int(j)
    num.append(x)

result = num[0]
for i in range(1, len(num)):
    result -= num[i]
print(result)
