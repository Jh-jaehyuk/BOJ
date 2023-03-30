import sys
from string import ascii_lowercase

l, c = map(int, sys.stdin.readline().split())
arr = sorted(list(sys.stdin.readline().rstrip().split()))
vowel = ['a', 'e', 'i', 'o', 'u']
conso = list(set(ascii_lowercase) - set(vowel))
tmp = []

def dfs(start):
    global tmp
    if len(tmp) == l:
        count = 0
        for i in conso:
            if i in tmp:
                count += 1
        for j in vowel:
            if j in tmp and count >= 2:
                print(''.join(tmp))
                return

    for i in range(start, c):
        if arr[i] not in tmp:
            tmp += arr[i]
            dfs(i + 1)
            tmp.pop()

dfs(0)
