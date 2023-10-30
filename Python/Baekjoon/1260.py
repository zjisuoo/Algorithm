from collections import deque
import sys
input = sys.stdin.readline

def bfs(V) :
	q = deque()
	q.append(V)
	visited_b[V] = 1
	while q :
		V = q.popleft()
		print(V, end = " ")
		for i in range(1, N+1) :
			if visited_b[i] == 0 and graph[V][i] == 1 :
				q.append(i)
				visited_b[i] = 1

def dfs(V) :
	visited_d[V] = 1
	print(V, end = " ")
	for i in range(1, N+1) : 
		if visited_d[i] == 0 and graph[V][i] == 1 :
			dfs(i)

N, M, V = map(int, input().split())

graph = [[0] * (N+1) for _ in range(N+1)]
visited_b = [0] * (N+1)
visited_d = [0] * (N+1)

for _ in range(M) :
	a, b = map(int, input().split())
	graph[a][b] = graph[b][a] = 1

dfs(V)
print()
bfs(V)

