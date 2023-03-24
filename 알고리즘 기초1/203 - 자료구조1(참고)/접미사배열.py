import sys

s = sys.stdin.readline().rstrip()
arr = []
for i in range(len(s)):
    arr.append(s[i:])

for j in sorted(arr):
    print(j)
