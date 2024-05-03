import sys
input = sys.stdin.readline
from collections import deque

N = int(input())
# enumerate 초기 인덱스 정보 유지
d = deque(enumerate(map(int, input().split())))
answer = []

while d :
	index, paper = d.popleft()
	answer.append(index + 1)

	if paper > 0 :
		d.rotate(-(paper - 1))
	elif paper < 0 :
		d.rotate(-paper)

print(' '.join(map(str, answer)))