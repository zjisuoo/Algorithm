import sys

N, K = map(int, sys.stdin.readline().split())
A = list()

for i in range(N) :
	A.append(int(input()))

count = 0
for i in reversed(range(N)) :
	count += K // A[i]
	K = K % A[i]

print(count)
