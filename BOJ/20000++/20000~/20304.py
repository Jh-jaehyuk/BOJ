from collections import deque

n = int(input())
m = int(input())
p = list(map(int, input().split()))

max_val = -1
queue = deque()

distance = [int(1e9)] * (n + 1)

for p_value in p:
    distance[p_value] = 0
    queue.append(p_value)

while queue:
    now = queue.popleft()

    for i in range(20):
        tmp = (1 << i) ^ now

        if tmp > n:
            continue

        if distance[now] + 1 >= distance[tmp]:
            continue

        distance[tmp] = distance[now] + 1
        max_val = max(max_val, distance[tmp])
        queue.append(tmp)

print(max_val)

