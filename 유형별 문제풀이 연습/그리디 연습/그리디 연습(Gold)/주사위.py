N = int(input())
dice = list(map(int, input().split()))
a, b, c, d, e, f = dice
arr = sorted([min(a, f), min(b, e), min(c, d)])

if N == 1:
    print(sum(dice) - max(dice))

else:
    print((arr[0] * (5 * (N * N) - 8 * N + 4)) + (arr[1] * (8 * N - 8)) + arr[2] * 4)
