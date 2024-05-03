N, M = map(int, input().split())
A = list(map(int, input().split()))
C = list(map(int, input().split()))

dp = [[0 for _ in range(10000 + 1)] for _ in range(N+1)]

for i in range(1, N+1) :
	for j in range(10000+1) :
		if C[i-1] <= j :
			dp[i][j] = max(A[i-1] + dp[i-1][j-C[i-1]], dp[i-1][j])
		else :
			dp[i][j] = dp[i-1][j]

for i, c in enumerate(dp[-1]) :
	if c >= M :
		print(i)
		break