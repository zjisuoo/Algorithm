def fib(N) :
	if N == 1 or N == 2 :
		return 1
	else :
		return fib(N-1) + fib(N-2)

def fibonacci(N) :
	fi = [0] * (N+1)
	fi[1], fi[2] = 1, 1
	cnt = 0 
	for i in range(3, N+1) :
		cnt += 1
		fi[i] = fi[i-1]+fi[i-2]
	return cnt

N = int(input())
print(fib(N), fibonacci(N))