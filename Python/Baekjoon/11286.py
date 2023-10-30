import heapq
import sys

N = int(input())
X = []

for _ in range(N) :
	x = int(sys.stdin.readline())
	if x != 0 :
		heapq.heappush(X, (abs(x), x))
	else :
		if not X :
			print(0)
		else :
			print(heapq.heappop(X)[1])
