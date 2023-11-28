import sys

n, r = map(int, sys.stdin.readline().split())
cities = set(sys.stdin.readline().rstrip().split())
n = len(cities)
m = int(sys.stdin.readline())
arr = sys.stdin.readline().rstrip().split()
INF = int(1e10)
distance1 = [[INF] * n for _ in range(n)]
distance2 = [[INF] * n for _ in range(n)]
is_free = {"ITX-Saemaeul", "ITX-Cheongchun", "Mugunghwa"}
is_half = {"S-Train", "V-Train"}

name_dict = dict()
idx = 0

for city in cities:
    name_dict[city] = idx
    idx += 1

for i in range(n):
    distance1[i][i] = 0
    distance2[i][i] = 0

k = int(sys.stdin.readline())
for _ in range(k):
    tr, u, v, cost = sys.stdin.readline().rstrip().split()
    cost = int(cost)
    u = name_dict[u]
    v = name_dict[v]

    if tr in is_free:
        distance1[u][v] = 0
        distance1[v][u] = 0
        distance2[u][v] = min(distance2[u][v], cost)
        distance2[v][u] = min(distance2[v][u], cost)

    elif tr in is_half:
        distance1[u][v] = min(distance1[u][v], cost / 2)
        distance1[v][u] = min(distance1[v][u], cost / 2)
        distance2[u][v] = min(distance2[u][v], cost)
        distance2[v][u] = min(distance2[v][u], cost)

    else:
        distance1[u][v] = min(distance1[u][v], cost)
        distance1[v][u] = min(distance1[v][u], cost)
        distance2[u][v] = min(distance2[u][v], cost)
        distance2[v][u] = min(distance2[v][u], cost)

for k in range(n):
    for i in range(n):
        for j in range(n):
            distance1[i][j] = min(distance1[i][j], distance1[i][k] + distance1[k][j])
            distance2[i][j] = min(distance2[i][j], distance2[i][k] + distance2[k][j])

val1 = r
val2 = 0
for i in range(m - 1):
    city, ncity = name_dict[arr[i]], name_dict[arr[i + 1]]
    val1 += distance1[city][ncity]
    val2 += distance2[city][ncity]

print("No" if val1 >= val2 else "Yes")
