N = int(input())

dp1 = 1
dp2 = 2
result = 1 if N == 1 else 2

for i in range(3, N+1) :
	result = (dp1 + dp2) % 15746
	dp1, dp2 = dp2, result
print(result)
