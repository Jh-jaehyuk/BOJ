import sys

r, c = map(int, sys.stdin.readline().split())
arr = [list(sys.stdin.readline().rstrip()) for _ in range(r)]

left = 0
right = len(arr) - 1


def check(x):
    check_set = set()
    for col in range(c):
        s = ''
        for row in range(x, r):
            s += arr[row][col]

        if s not in check_set:
            check_set.add(s)
        else:
            return True
    return False


result = 0

while left <= right:
    mid = (left + right) // 2

    if check(mid):
        right = mid - 1
    else:
        result = mid
        left = mid + 1

print(result)
