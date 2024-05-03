A = []
N, K = map(int, input().split())
cnt = 0

for i in range(1, N+1) :
	if N % i == 0:
		A.append(i)
	cnt += 1

if K > len(A) :
	print(0)
else : 
	print(A[K-1])