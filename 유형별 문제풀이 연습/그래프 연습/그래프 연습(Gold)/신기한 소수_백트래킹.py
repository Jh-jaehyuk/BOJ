def is_prime(x):
    if x == 0 or x == 1:
        return False
    for i in range(2, int(x ** 0.5) + 1):
        if x % i == 0:
            return False
    return True


n = int(input())
tmp = []


def bfs():
    if len(tmp) == n:
        print(*tmp, sep="")
        return

    for i in range(10):
        if not tmp and is_prime(i):
            tmp.append(str(i))
            bfs()
            tmp.pop()

        elif tmp:
            for idx in range(1, len(tmp) + 2):
                check = int(''.join(tmp + [str(i)])[:idx])
                if not is_prime(check):
                    break
            else:
                tmp.append(str(i))
                bfs()
                tmp.pop()


bfs()
