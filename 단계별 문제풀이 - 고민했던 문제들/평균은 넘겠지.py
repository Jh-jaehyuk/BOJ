import sys
c = int(input())
for _ in range(c):
    array = list(map(int, sys.stdin.readline().split()))
    x = 0
    avg = sum(array[1:]) / array[0]
    for i in array[1:]:
        if i > avg:
            x += 1
    ratio = (x / array[0]) * 100
    # 소수점 아래 3자리로 제한(f-string 이용)
    print(f'{ratio:.3f}', end='')
    print('%')
