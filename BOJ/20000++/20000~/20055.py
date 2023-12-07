import sys
from collections import deque

n, k = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))
arr = deque(A)
visited = deque([False] * (2 * n))
queue = deque()


def check():
    count = 0
    for i in arr:
        if i == 0:
            count += 1

    if count >= k:
        return True
    return False


result = 0
while True:
    result += 1

    arr.rotate(1)
    visited.rotate(1)

    for _ in range(len(queue)):
        v = queue.popleft()
        if v + 1 == n - 1:
            visited[v + 1] = False
            continue
        queue.append(v + 1)

    for _ in range(len(queue)):
        v = queue.popleft()

        if not visited[v + 1] and arr[v + 1] > 0:
            visited[v] = False
            arr[v + 1] -= 1

            if v + 1 == n - 1:
                continue
            visited[v + 1] = True
            queue.append(v + 1)

        else:
            queue.append(v)

    if not visited[0] and arr[0] > 0:
        visited[0] = True
        arr[0] -= 1
        queue.append(0)

    if check():
        break

print(result)
