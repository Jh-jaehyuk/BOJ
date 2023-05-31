n = int(input())
if n == 1:
    print(2)
    quit(0)

for i in range(n, 1100000):
    for j in range(2, int(i ** 0.5) + 1):
        if i % j == 0:
            break
    else:
        x = str(i)
        if x == x[::-1]:
            print(i)
            quit(0)
