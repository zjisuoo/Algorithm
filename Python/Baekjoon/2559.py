import sys

N, K = map(int, sys.stdin.readline().split())
temp = list(map(int, sys.stdin.readline().split()))
temp_sum = sum(temp[:K])
result = [temp_sum]

for i in range(N-K) :
	temp_sum = temp_sum - temp[i] + temp[i+K]
	result.append(temp_sum)

print(max(result))
