N, M = map(int, input().split())
A = [0] * (N)

for x in range(M) :
	i, j, k = map(int, input().split())
	for y in range(i, j+1, 1) :
		A[y-1] = k

for x in range(N) :
	print(A[x], '', end = '')
