N = int(input())


def draw_star(x):
    if x == 3:
        return '***\n* *\n***'
    else:
        arr = []
        k = draw_star(x // 3)
        for i in range(x // 3):
            arr.append(k[i * (x // 3) + i:(i + 1) * (x // 3) + i] * 3)
        arr *= 3

        for i in range(x // 3, 2 * x // 3):
            arr[i] = arr[i][0:x // 3] + ' ' * (x // 3) + arr[i][2 * x // 3:x]

        return '\n'.join(arr)


print(draw_star(N))
