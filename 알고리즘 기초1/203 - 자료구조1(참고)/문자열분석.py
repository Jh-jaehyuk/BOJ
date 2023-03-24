import sys

while True:
    try:
        s = sys.stdin.readline().rstrip('\n')
        if s == '':
            break
        arr = [0] * 4
        for i in s:
            if i.islower():
                arr[0] += 1
            elif i.isupper():
                arr[1] += 1
            elif i.isdigit():
                arr[2] += 1
            else:
                arr[3] += 1
        print(*arr)
    except EOFError:
        break
