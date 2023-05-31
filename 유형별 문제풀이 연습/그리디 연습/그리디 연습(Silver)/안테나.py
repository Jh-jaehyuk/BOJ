n = int(input())
house = list(map(int, input().split()))
house.sort()
idx = len(house) // 2

if len(house) % 2 == 0:
    idx -= 1
print(house[idx])
