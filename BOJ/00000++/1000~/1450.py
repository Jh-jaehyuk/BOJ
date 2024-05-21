from bisect import bisect_right

n, c = map(int, input().split())
A = list(map(int, input().split()))
lq = []
rq = []

def DFS(l, r, total, s):
    if l >= r:
        s.append(total)
        return
    DFS(l + 1, r, total, s)
    DFS(l + 1, r, total + A[l], s)

DFS(0, n // 2, 0, lq)
DFS(n // 2, n, 0, rq)

rq.sort()
ans = 0
for i in range(len(lq)):
    ans += bisect_right(rq, c - lq[i])
print(ans)
