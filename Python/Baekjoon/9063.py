N = int(input())
ground = []

for i in range(N) :
	x, y = map(int(input().split()))
	ground[0].append(x)
	ground[1].append(y)

print(ground)

