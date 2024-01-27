# your code goes here
import sys

T = int(sys.stdin.readline())


def solve(n):
	arr = list(map(int, sys.stdin.readline().rstrip().split()))
	team_num = max(arr)
	team_list = [[] for _ in range(team_num + 1)]
	score = [0] * (team_num + 1)
	
	for i in range(n):
		team = arr[i]
		team_list[team].append(i + 1)
	
	count = [0] * (team_num + 1)
	val = 0
	for i in range(n):
		team = arr[i]
		
		if len(team_list[team]) < 6:
			val -= 1
			continue
		
		if count[team] < 4:
			score[team] += (i + 1) + val
			count[team] += 1
		
	Min = int(1e9)
	for i in range(1, team_num + 1):
		if score[i] == 0:
			continue
		Min = min(Min, score[i])
	
	result = []
	for i in range(1, team_num + 1):
		if score[i] == Min:
			result.append(i)

	result.sort(key=lambda x: team_list[x][4])
	print(result[0])
	
	
for t in range(T):
	N = int(sys.stdin.readline())
	solve(N)
