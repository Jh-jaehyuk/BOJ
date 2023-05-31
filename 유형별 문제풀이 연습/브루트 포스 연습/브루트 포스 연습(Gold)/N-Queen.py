import sys
n = int(sys.stdin.readline())
result = 0
row = [0] * n


def promising(x):
    for i in range(x):
        if row[x] == row[i] or abs(row[x] - row[i]) == abs(x - i):
            return False
    return True


def n_queens(x):
    global result
    if x == n:
        result += 1

    else:
        for i in range(n):
            row[x] = i
            if promising(x):
                n_queens(x + 1)


n_queens(0)
print(result)
