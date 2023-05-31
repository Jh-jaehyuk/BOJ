import sys

n = int(sys.stdin.readline())
arr = [('@', 'a'), ('[', 'c'), ('!', 'i'), (';', 'j'), ('^', 'n'), ('0', 'o'), ('7', 't'), (r"\\'", 'w'), (r"\'", 'v')]

for _ in range(n):
    s = sys.stdin.readline().rstrip()
    count = 0

    for i in arr:
        if i[0] in s:
            count += s.count(i[0])
            s = s.replace(i[0], i[1])

    length = len(s)

    if count < round(length / 2, 1):
        print(s)
    else:
        print("I don't understand")
