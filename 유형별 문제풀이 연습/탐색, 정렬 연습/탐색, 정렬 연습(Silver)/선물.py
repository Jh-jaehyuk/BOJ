n, l, w, h = map(int, input().split())

left = 0
right = max(l, w, h)
mid = (left + right) / 2
i = 0

while left < right and i < 10000:
    mid = (left + right) / 2
    _l, _w, _h = int(l / mid), int(w / mid), int(h / mid)
    if _l * _w * _h >= n:
        left = mid
    else:
        right = mid
    i += 1

print(mid)

