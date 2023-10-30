from itertools import combinations

N = int(input())
S = [list(map(int, input().split())) for _ in range(N)]
members = [i for i in range(N)]
possible_team = []

for team in list(combinations(members, N//2)) :
	possible_team.append(team)

min_start_gap = 10000

for i in range(len(possible_team)//2) :
	team = possible_team[i]
	start_A = 0
	for j in range(N//2) :
		member = team[j]
		for k in team :
			start_A += S[member][k]

	team = possible_team[-i-1]
	start_B = 0
	for j in range(N//2) :
		member = team[j]
		for k in team :
			start_B += S[member][k]

	min_start_gap = min(min_start_gap, abs(start_A - start_B))

print(min_start_gap)