A, B = -1, -1

for a in range(1, 10):
    print("? A", a, flush=True)
    res = int(input())

    if res:
        A = a
        break

for b in range(1, 10):
    print("? B", b, flush=True)
    res = int(input())

    if res:
        B = b
        break

print("!", A + B)