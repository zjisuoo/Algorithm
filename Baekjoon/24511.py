import sys
input = sys.stdin.readline
from collections import deque

N = int(input())
list_a = list(map(int, input().split()))
list_b = list(map(int, input().split()))

M = int(input())
list_c = list(map(int, input().split()))

answer = deque()

for i in range(N) :
	if list_a[i] == 0 :
		answer.appendleft(list_b[i])

for j in range(M) :
	answer.append(list_c[j])
	print(answer.popleft(), end = ' ')