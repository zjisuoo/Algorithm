import sys

N, M = map(int, sys.stdin.readline().split())
num = list(map(int, sys.stdin.readline().split()))
num_sum = [0]
temp = 0

for i in num :
	temp += i
	num_sum.append(temp)

for _ in range(M) :
	i, j = map(int, sys.stdin.readline().split())
	print(num_sum[j] - num_sum[i-1])

