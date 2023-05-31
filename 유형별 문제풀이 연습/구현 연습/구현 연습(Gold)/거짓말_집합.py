import sys

n, m = map(int, sys.stdin.readline().split())
know = set(map(int, sys.stdin.readline().split()[1:]))
party = []

for _ in range(m):
    party.append(set(map(int, sys.stdin.readline().split()[1:])))

for _ in range(m):
    for p in party:
        if p & know:
            know = know.union(p)

count = 0

for p in party:
    if p & know:
        continue
    count += 1
print(count)
