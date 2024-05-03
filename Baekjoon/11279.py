import heapq
import sys

N = int(input())
X = []

for i in range(N) :
	x = int(sys.stdin.readline())
	if x : 
		heapq.heappush(X, (-x, x))
	else :
		if len(X) >= 1 :
			print(heapq.heappop(X)[1])
		else :
			print(0)
