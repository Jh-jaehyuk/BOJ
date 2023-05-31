n = int(input())
tmp = []


def solution(idx):
    for i in range(1, (idx // 2) + 1):
        if tmp[-i:] == tmp[-2 * i:-i]:
            return -1

    if idx == n:
        for i in range(n):
            print(tmp[i], end='')
        return 0

    for i in range(1, 4):
        tmp.append(i)
        if solution(idx + 1) == 0:
            return 0
        tmp.pop()


solution(0)
