import sys
from collections import deque, defaultdict

n = int(sys.stdin.readline())

indegree = defaultdict(int)
graph = defaultdict(list)
result = defaultdict(list)

arr = sorted(list(sys.stdin.readline().rstrip().split()))
m = int(sys.stdin.readline())

for _ in range(m):
    x, y = sys.stdin.readline().rstrip().split()
    indegree[x] += 1
    graph[y].append(x)

K = 0
Kl = []
queue = deque()

for name in arr:
    if indegree[name] == 0:
        queue.append(name)
        K += 1
        Kl.append(name)

print(K)
print(*Kl)

while queue:
    now = queue.popleft()

    for i in graph[now]:
        indegree[i] -= 1

        if indegree[i] == 0:
            result[now].append(i)
            queue.append(i)

for i in arr:
    print(i, end=" ")

    if len(result[i]) == 0:
        print(0)
        continue

    else:
        print(len(result[i]), end=" ")
        print(*sorted(result[i]))