N = int(input())

# 안마심/마심(직전)/마심(직전 안먹음)
dp = [[0, 0, 0]]
for i in range(1, N+1):
    wine=int(input())
    if i == 1:
        dp.append([0, wine, 0])
    else:
        dp.append([max(dp[i-1]), max(dp[i-2]) + wine, dp[i-1][1] + wine])
print(max(dp[-1]))