s = input()
start, end = 0, len(s) - 1

while start <= end:
    if s[start] != s[end]:
        print(len(s))
        exit(0)
    start += 1
    end -= 1

start = 0
end = len(s) - 2

while start <= end:
    if s[start] != s[end]:
        print(len(s) - 1)
        exit(0)
    start += 1
    end -= 1

print(-1)