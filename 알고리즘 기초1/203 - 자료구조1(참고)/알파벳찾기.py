import sys

s = sys.stdin.readline().rstrip()
arr = [-1] * 26
for i in s:
    arr[ord(i) - ord('a')] = s.find(i)
print(*arr)
