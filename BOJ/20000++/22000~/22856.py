import sys

n = int(sys.stdin.readline())

left = [0] * (n + 1)
right = [0] * (n + 1)
parent = [0] * (n + 1)
visited = [False] * (n + 1)

parent[1] = -1

for _ in range(n):
    a, b, c = map(int, sys.stdin.readline().split())
    left[a] = b
    right[a] = c

    if b != -1:
        parent[b] = a
    if c != -1:
        parent[c] = a

end = 1

while right[end] != -1:
    end = right[end]

now = 1
result = -1

while True:
    visited[now] = True
    result += 1

    if left[now] != -1 and not visited[left[now]]:
        now = left[now]

    elif right[now] != -1 and not visited[right[now]]:
        now = right[now]

    else:
        if now == end:
            break
        else:
            now = parent[now]

print(result)
