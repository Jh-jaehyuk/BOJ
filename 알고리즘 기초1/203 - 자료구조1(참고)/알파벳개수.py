import sys

s = sys.stdin.readline().rstrip()
arr = [0] * 26
for i in s:
    arr[ord(i) - ord('a')] += 1
print(*arr)
