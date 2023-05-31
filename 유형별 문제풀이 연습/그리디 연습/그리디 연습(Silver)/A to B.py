a, b = map(int, input().split())
count = 0

while a < b:
    if str(b)[-1] == '1':
        b = int(str(b)[:-1])
        count += 1
        continue

    if b % 2 == 0:
        b //= 2
        count += 1
    else:
        break

if a == b:
    count += 1
else:
    count = -1
print(count)
