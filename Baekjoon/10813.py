N, M = map(int, input().split())
A = [i for i in range(1, N+1)]

for i in range(M) :
	a, b = map(int, input().split())
	temp = A[b-1]
	A[b-1] = A[a-1]
	A[a-1] = temp
	
print(*A)