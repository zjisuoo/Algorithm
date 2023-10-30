from collections import deque

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def bfs(graph, a, b) :
	N = len(graph)
	queue = deque()
	queue.append((a, b))
	graph[a][b] = 0
	count = 1 

	while queue :
		x, y = queue.popleft()
		for i in range(4) :
			nx = x + dx[i]
			ny = y + dy[i]
			if nx < 0 or nx >= N or ny < 0 or ny >= N :
				continue
			if graph[nx][ny] == 1 :
				graph[nx][ny] = 0
				queue.append((nx, ny))
				count += 1
	return count

T = int(input())

for i in range(T) :
	M, N, K = map(int, input().split())
	graph = [[0] * (N) for _ in range(M)]
	cnt = 0

	for j in range(K) :
		x, y = map(int, input().split())
		graph[x][y] = 1

	for a in range(M) :
		for b in range(N) :
			if graph[a][b] == 1 :
				bfs(a, b)
				cnt += 1

	print(cnt)





