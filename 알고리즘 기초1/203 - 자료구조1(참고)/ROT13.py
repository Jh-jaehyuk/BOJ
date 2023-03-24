import sys
import string

arr1 = list(string.ascii_lowercase) * 2
arr2 = list(string.ascii_uppercase) * 2

s = sys.stdin.readline().rstrip()
answer = ''
for i in s:
    if i.isupper():
        answer += arr2[ord(i) - ord('A') + 13]
    elif i.islower():
        answer += arr1[ord(i) - ord('a') + 13]
    else:
        answer += i

print(answer)
