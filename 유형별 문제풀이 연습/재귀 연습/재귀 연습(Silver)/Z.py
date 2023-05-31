N, r, c = map(int, input().split())
answer = 0


def solution(x, y, n):
    global answer
    if x == r and y == c:
        print(answer)
        quit(0)
    if n == 1:
        answer += 1
        return
    if not (x <= r < x + n and y <= c < y + n):
        answer += n * n
        return
    tmp = n // 2
    solution(x, y, tmp)
    solution(x, y + tmp, tmp)
    solution(x + tmp, y, tmp)
    solution(x + tmp, y + tmp, tmp)


solution(0, 0, 2 ** N)
print(answer)
