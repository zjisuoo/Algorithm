import sys

N, M = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split())) + [0]

count = [0] * M

for i in range(N) :ㅌ
	A[i] += A[i-1]
	count[A[i] % M] += 1

result = count[0]

for i in count :
	result += i * (i-1) // 2

print(result)

