import sys
input = sys.stdin.readline

x = [1, -1, 1, -1, 2, -2, 2, -2]
y = [2, 2, -2, -2 ,1, 1, -1, -1]

T = int(input())

def bfs(c_x, c_y) :
	queue = []
	queue.append((c_x, c_y))
	C[c_x][c_y] += 1

	while queue :
		c_x, c_y = queue.pop(0)
		
		if c_x == e_x and c_y == e_y :
			return C[c_x][c_y]

		for dx, dy in zip(x, y) :
			nx = c_x + dx
			ny = c_y + dy
			if 0 <= nx < size and 0 <= ny < size and C[nx][ny] == -1 :
				queue.append((nx, ny))
				C[nx][ny] = C[c_x][c_y] + 1

for _ in range(T) :
	size = int(input())
	C = [[-1] * size for _ in range(size)]
	s_x, s_y = map(int, input().split())
	e_x, e_y = map(int, input().split())
	print(bfs(s_x, s_y))
