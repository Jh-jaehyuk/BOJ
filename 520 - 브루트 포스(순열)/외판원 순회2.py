import sys

n = int(sys.stdin.readline())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
answer = int(1e9)
visited = [False] * n

def dfs(start, now, cost, count):
    global answer
    if count == n:
        if arr[now][start]:
            cost += arr[now][start]
            if answer > cost:
                answer = cost
        return

    if cost > answer:
        return

    for i in range(n):
        if not visited[i] and arr[now][i]:
            visited[i] = True
            dfs(start, i, cost + arr[now][i], count + 1)
            visited[i] = False

for j in range(n):
    visited[j] = True
    dfs(j, j, 0, 1)
    visited[j] = False

print(answer)
# 참고 : https://velog.io/@y7y1h13/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98%EB%B0%B1%EC%A4%80-10971%EB%B2%88-%EC%99%B8%ED%8C%90%EC%9B%90-%EC%88%9C%ED%9A%8C-2python
