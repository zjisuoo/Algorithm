N = int(input())
road = list(map(int, input().split()))
cost = list(map(int, input().split()))

result = road[0] * cost[0]
m = cost[0]
dist = 0
for i in range(1, N-1) :
	if cost[i] < m :
		result += m * dist
		dist = road[i]
		m = cost[i]
	else :
		dist += road[i]

	if i == N-2 :
		result += m * dist
print(result)
