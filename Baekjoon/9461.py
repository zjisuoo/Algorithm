P = [0 for i in range(101)]
P[1] = 1
P[2] = 1
P[3] = 1

for i in range (4, 101) :
	P[i] = P[i-2] + P[i-3]

T = int(input())

for i in range(T) :
	N = int(input())
	print(P[N])