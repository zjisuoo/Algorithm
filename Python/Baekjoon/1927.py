import heapq
import sys

N = int(input())
X = []

for _ in range(N) :
    x = int(sys.stdin.readline())
    if x != 0 :
        heapq.heappush(X, x)
    else :
        try :
            print(heapq.heappop(X))
        except :
            print(0)