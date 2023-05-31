# CCW Algorithm
x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
x3, y3 = map(int, input().split())
# 벡터의 외적 이용
result = ((x2 - x1) * (y3 - y1)) - ((x3 - x1) * (y2 - y1))
# 외적값이 0이라면 직선
if result == 0:
    print(result)
# 양수라면 반시계방향
elif result > 0:
    print(1)
# 음수라면 시계방향
else:
    print(-1)
