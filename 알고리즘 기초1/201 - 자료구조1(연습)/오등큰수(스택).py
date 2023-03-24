import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
count = [0] * 1000001
answer = [-1] * n
stack = []

for i in range(len(arr)):
    count[arr[i]] += 1

for i in range(len(arr)):
    while stack and count[arr[stack[-1]]] < count[arr[i]]:
        answer[stack.pop()] = arr[i]
    stack.append(i)

print(*answer)
