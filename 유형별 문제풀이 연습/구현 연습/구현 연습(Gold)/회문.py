T = int(input())


def check(s):
    length = len(s)
    if length == 1:
        return [True]

    for i in range(length // 2):
        if s[i] != s[length - 1 - i]:
            return [False, i]
    else:
        return [True]


for _ in range(T):
    s = input()
    idx = -1

    if check(s)[0]:
        print(0)
        continue
    else:
        idx = check(s)[1]
        s1 = s[:idx] + s[(idx + 1):]
        s2 = s[:(len(s) - 1 - idx)] + s[(len(s) - idx):]

        if check(s1)[0] or check(s2)[0]:
            print(1)
        else:
            print(2)
