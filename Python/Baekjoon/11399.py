N = int(input())
P = list(map(int, input().split()))

P.sort()
ATM_sum = 0
for i in range(N) :
	for j in range(i+1) :
		ATM_sum += P[j]

print(ATM_sum)