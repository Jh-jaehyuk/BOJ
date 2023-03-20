import sys
n = int(sys.stdin.readline())
a = n - len(str(n)) * 9
if a < 0:
    a = 0

for i in range(a, n + 1):
    array = [int(j) for j in str(i)]
    array.append(i)
    if sum(array) == n:
        print(i)
        quit()

print(0)
