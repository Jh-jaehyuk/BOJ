x, y, k = map(int, input().split())


def get_rate(mana):
    div = mana // x

    if mana % x > 0:
        div += 1

    mod = mana // (x + y)

    if mana % (x + y) > 0:
        mod += 1

    return div / mod


result = k
rate = get_rate(k)
val = k

for i in range(k, k + x + y + 1):
    if i % (x + y) == 1:
        val = i
        break

for i in range(x + 1):
    _val = val + (x + y) * i
    _rate = get_rate(_val)

    if _rate < rate:
        result = _val
        rate = _rate

print(result)
