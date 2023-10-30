from collections import deque
from sys import stdin
import copy

def bfs() :
	queue = deque()
	#lab_graph = copy.deepcopy(graph)
	#copy_list_b = [item[:] for item in origin_list]
	lab_graph = [item[:] for item in graph]

	for i in range(n) :
		for j in range(m) :
			if lab_graph[i][j] == 2 :
				queue.append((i, j))

	while queue :
		x, y = queue.popleft() 

		for i in range(4) :
			nx = x + dx[i]
			ny = y + dy[i]

			if nx >= 0 and nx < n and ny >= 0 and ny < m :
				if lab_graph[nx][ny] == 0 :
					lab_graph[nx][ny] = 2 
					queue.append((nx, ny))

	global answer
	cnt = 0

	for i in range(n) :
	 	cnt += lab_graph[i].count(0)

	answer = max(answer, cnt)

def result(wallCnt) :
	if wallCnt == 3 :
		bfs()
		return

	for i in range(n) :
		for j in range(m) :
			if graph[i][j] == 0 :
				graph[i][j] = 1
				result(wallCnt+1)
				graph[i][j] = 0

n, m = map(int, stdin.readline().rstrip().split())
graph = []
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

for i in range(n) :
	graph.append(list(map(int, input().split())))

answer = 0
result(0)
print(answer)



