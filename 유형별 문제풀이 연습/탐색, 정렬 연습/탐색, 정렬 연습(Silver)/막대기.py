import heapq

X = int(input())
stick = []
heapq.heappush(stick, 64)

while sum(stick) != X:
    min_stick = heapq.heappop(stick)
    min_stick //= 2
    heapq.heappush(stick, min_stick)
    if sum(stick) < X:
        heapq.heappush(stick, min_stick)

print(len(stick))
