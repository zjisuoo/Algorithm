#N, M = map(int, input().split())

#최대공약수
#for i in range(min(N, M), 0, -1) :
#	if N % i == 0 and M % i == 0 :
#		print(i)
#		break

#최소공배수
#for i in range(max(N, M), (N * M) + 1) :
#	if i % N == 0 and i % M == 0 :
#		print(i)
#		break


import math

a, b = map(int, input().split())

print(math.gcd(a, b))
print(math.lcm(a, b))