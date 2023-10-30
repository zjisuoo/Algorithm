N, M = map(int, input().strip().split())
A = [i for i in range(1, N+1)]

for _ in range(M) :
	i, j = map(int, input().strip().split())
	A = A[0:i-1]+A[i-1:j][::-1]+A[j:]

print(" ".join(str(e) for e in A))