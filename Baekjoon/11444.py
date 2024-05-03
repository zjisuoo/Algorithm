import sys
input = sys.stdin.readline

p = 1000000007

#분할정복-제곱
def power(f, N) :
	if N == 1 :
		return f
	elif N % 2 :
		return mul(power(f, N-1), f)
	else :
		return power(mul(f, f), N//2)

def mul(A, B) :
	tmp = [[0] * len(B[0]) for _ in range(2)]
	for i in range(2) :
		for j in range(len(B[0])) :
			sum = 0
			for k in range(2) :
				sum += A[i][k] * B[k][j]
			tmp[i][j] = sum % p
	return tmp

#초기행렬
f = [[1, 1], [1, 0]]
#피보나치 초기값
start = [[1], [1]]
N = int(input())
if N < 3 :
	print(1)
else :
	print(mul(power(f, N-2), start)[0][0])