from collections import deque

N = int(input())
v = int(input())
graph = [[] for i in range(N+1)]
visited = [0] * (N+1)

for i in range(v) :
	a, b = map(int, input().split())
	graph[a] += [b]
	graph[b] += [a]

visited[1] = 1
q = deque([1])

while q :
	count = q.popleft()
	for x in graph[count] :
		if visited[x] == 0 :
			q.append(x)
			visited[x] = 1

print(sum(visited)-1)