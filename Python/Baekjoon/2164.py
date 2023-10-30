N = int(input())
A = 2

while True :
	if N == 1 or N == 2 :
		print(N)
		break
	A *= 2

	if A >= N :
		print((N - (A//2)) * 2)
		break
