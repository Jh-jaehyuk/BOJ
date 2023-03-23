import sys

n, m = map(int, sys.stdin.readline().split())
arr = list()
for _ in range(n):
    arr.append(sys.stdin.readline().rstrip())
d = dict()
for i in range(1, len(arr) + 1):
    d[arr[i - 1]] = i

for _ in range(m):
    i = sys.stdin.readline().rstrip()
    if i.isdigit():
        # 리스트에서 값을 불러오는건 시간복잡도 O(1)
        print(arr[int(i) - 1])
    else:
        # dictionary에서 값을 불러오는 것도 시간복잡도 O(1)
        print(d[i])
