N, K = map(int, input().split())
coin = [int(input()) for i in range(N)]

dp = [0 for i in range(K+1)]
dp[0] = 1

for i in coin :
	for j in range(i, K+1) :
		if j-1 >= 0 :
			dp[j] += dp[j-i]

print(dp[K])