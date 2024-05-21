import sys
input = sys.stdin.readline

def solve(n, k):
    ans = []
    while n > 0:
        s = str(n)[0]
        ss = len(str(n))
        x = int(s * ss)
        if x <= n:
            n -= x
            ans.append(x)
        else:
            s = int(str(n)[0]) - 1
            if not s:
                s = 9
                ss -= 1
            s = str(s)
            n -= int(s * ss)
            ans.append(int(s * ss))
    return ans
    

T = int(input())
for _ in range(T):
    k, n = map(int, input().strip().split())
    res = solve(n, k)
    print(len(res))
    print(*res)
