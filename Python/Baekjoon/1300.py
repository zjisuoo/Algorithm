N = int(input())
K = int(input())

def binary_search(target, start, end) :
	while start <= end :
		mid = (start + end) // 2

		cnt = 0

		for i in range(1, N+1) :
			cnt += min(mid//i, N)

		if cnt >= target :
			end = mid -1
		else :
			start = mid + 1
	return start

print(binary_search(K, 1, N*N))