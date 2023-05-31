import sys


def recursion(s, l, r, t):
    if l >= r:
        return [1, t]
    elif s[l] != s[r]:
        return [0, t]
    else:
        return recursion(s, l + 1, r - 1, t + 1)


def isPalindrome(s, t):
    return recursion(s, 0, len(s) - 1, t + 1)


T = int(sys.stdin.readline())

for _ in range(T):
    s = sys.stdin.readline().strip()
    result = isPalindrome(s, 0)
    print(*result)
