import sys
import heapq

n, m = map(int, sys.stdin.readline().split())
arr = []
max_val = -1
heap = []

for i in range(n):
    tmp = sorted(list(map(int, sys.stdin.readline().split())))
    max_val = max(max_val, tmp[0])
    arr.append(tmp)
    heapq.heappush(heap, (tmp[0], i, 0))

result = int(1e10)

while heap:
    min_val, min_arr, min_idx = heapq.heappop(heap)
    result = min(result, max_val - min_val)

    if min_idx + 1 == m:
        break

    max_val = max(max_val, arr[min_arr][min_idx + 1])
    heapq.heappush(heap, (arr[min_arr][min_idx + 1], min_arr, min_idx + 1))

print(result)
