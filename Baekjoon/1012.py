from collections import deque

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def bfs(graph, a, b) :
	queue = deque()
	queue.append((a, b))
	graph[a][b] = 0

	while queue :
		x, y = queue.popleft()
		for i in range(4) :
			nx = x + dx[i]
			ny = y + dy[i]
			if nx < 0 or nx >= N or ny < 0 or ny >= M :
				continue
			if graph[nx][ny] == 1 :
				graph[nx][ny] = 0
				queue.append((nx, ny))

	return
				
T = int(input())

for i in range(T) :
	N, M, K = map(int, input().split())
	graph = [[0] * (M) for _ in range(N)]
	cnt = 0

	for j in range(K) :
		x, y = map(int, input().split())
		graph[x][y] = 1

	for a in range(N) :
		for b in range(M) :
			if graph[a][b] == 1 :
				bfs(graph, a, b)
				cnt += 1

	print(cnt)