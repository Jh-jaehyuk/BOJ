N, K = map(int, input().split())

count = 0
arr = []

for i in range(2, N + 1):
    for j in range(i, N + 1, i):
        if j not in arr:
            count += 1
            arr.append(j)
        if count == K:
            print(j)
            quit(0)
