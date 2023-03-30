import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

for i in range(n - 1, 0, -1):
    if arr[i - 1] < arr[i]:
        for j in range(n - 1, 0, -1):
            if arr[i - 1] < arr[j]:
                arr[i - 1], arr[j] = arr[j], arr[i - 1]
                arr = arr[:i] + sorted(arr[i:])
                print(*arr)
                quit()
print(-1)

# N의 범위가 0이상 10000이하이기 때문에 DFS로 풀이 불가.
