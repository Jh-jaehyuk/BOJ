n = int(input())
distance = [list(map(int, input().split())) for _ in range(n)]
check = [[True] * n for _ in range(n)]
result = 0

for k in range(n):
    for i in range(n):
        for j in range(n):
            if i == j or j == k or k == i:
                continue

            if distance[i][k] + distance[k][j] == distance[i][j]:
                check[i][j] = False

            elif distance[i][k] + distance[k][j] < distance[i][j]:
                print(-1)
                exit(0)

for i in range(n):
    for j in range(n):
        if check[i][j]:
            result += distance[i][j]

print(result // 2)