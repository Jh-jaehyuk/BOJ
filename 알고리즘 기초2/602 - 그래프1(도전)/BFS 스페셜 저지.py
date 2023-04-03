import sys
from collections import deque, defaultdict

n = int(sys.stdin.readline())

graph = [[] for _ in range(n + 1)]
visited = [False] * (n + 1)

for _ in range(n - 1):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

check = list(map(int, sys.stdin.readline().split()))

def bfs():
    queue = deque([1])

    visited[1] = True

    while queue:
        v = queue.popleft()

        for i in graph[v]:
            if visited[i]:
                continue
            visited[i] = True
            children[v].append(i)
            queue.append(i)

children = defaultdict(list)

if check[0] != 1:
    print(0)

else:
    bfs()

    q = deque([1])
    idx = 1

    while q:
        tmp = q.popleft()

        x = set(children[tmp])
        length = len(x)
        y = check[idx:idx + length]
        q.extend(y)
        y = set(y)
        idx += length

        if x != y:
            print(0)
            exit()
    print(1)

# 참고 : https://dalseoin.tistory.com/entry/%EB%B0%B1%EC%A4%80-%ED%8C%8C%EC%9D%B4%EC%8D%AC-16940-BFS-%EC%8A%A4%ED%8E%98%EC%85%9C-%EC%A0%80%EC%A7%80
