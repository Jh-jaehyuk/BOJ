import sys

n, m = map(int, sys.stdin.readline().split())
team_dict = dict()
name_dict = dict()

for i in range(n):
    team = sys.stdin.readline().rstrip()
    team_dict[team] = []
    num = int(sys.stdin.readline())

    for _ in range(num):
        name = sys.stdin.readline().rstrip()
        team_dict[team].append(name)
        name_dict[name] = team

for i in range(m):
    p = sys.stdin.readline().rstrip()
    q = int(sys.stdin.readline())

    if q == 0:
        print(*sorted(team_dict[p]), sep='\n')

    else:
        print(name_dict[p])