N, M = map(int, input().split())

A = [i+1 for i in range(N)]

for _ in range(M) :
	begin, end, mid = map(int, input().split())
	A[begin-1:end]=A[mid-1:end]+A[begin-1:mid-1]

print(*A)