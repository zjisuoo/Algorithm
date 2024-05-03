#from sys import stdin
from collections import deque

N, M = map(int, input().split())
cleaning_area = []
cleaned = [[0] * M for _ in range(N)] 
r, c, d = map(int, input().split())

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

for _ in range(N) :
    cleaning_area.append(list(map(int, input().split())))

cleaned[r][c] = 1
cnt = 1

while 1 :
	direction = 0
	for _ in range(4) :
		nx = r + dx[(d+3) % 4]
		ny = c + dy[(d+3) % 4]

		d = (d+3) % 4

		if 0 <= nx < N and 0 <= ny < M and cleaning_area[nx][ny] == 0 :
				if cleaned[nx][ny] == 0 :
					cleaned[nx][ny] = 1
					cnt += 1
					r = nx
					c = ny
					direction = 1
					break

	if direction == 0 :
		if cleaning_area[r-dx[d]][c-dy[d]] == 1 : 
			print(cnt)
			break
		else :
			r, c = r - dx[d], c - dy[d]

