from collections import deque


n, w, l = map(int, input().split())
truck = list(map(int, input().split()))
truck = deque(truck)
count = 0
bridge = deque([0] * w)

while truck:
    if sum(bridge) + truck[0] <= l:
        bridge.popleft()
        bridge.append(truck.popleft())
        count += 1

    else:
        x = bridge.popleft()
        if sum(bridge) + truck[0] <= l:
            bridge.append(truck.popleft())
            count += 1
        else:
            bridge.append(0)
            count += 1

while sum(bridge) != 0:
    bridge.popleft()
    bridge.append(0)
    count += 1

print(count)
