N = int(input())
A = list(map(int, input().split()))

dp1 = [0 for i in range(N)]
dp2 = [0 for i in range(N)]
dp3 = [0 for i in range(N)]

for i in range(N):
    for j in range(i):
        if A[i] > A[j] and dp1[i] < dp1[j]:
            dp1[i] = dp1[j]
    dp1[i] += 1
    print(dp1)

for i in range(N-1, -1, -1) :
	for j in range(N-1, i, -1) :
		if A[i] > A[j] and dp2[i] < dp2[j] :
			dp2[i] = dp2[j]
	dp2[i] += 1
	print(dp2)

for i in range(N) :
	dp3[i] = dp1[i] + dp2[i] - 1

print(max(dp3))
    