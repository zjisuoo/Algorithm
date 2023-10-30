from collections import deque
import sys
input = sys.stdin.readline

N, M, R = map(int, input().split())
graph = [[] for _ in range(N+1)]
visited = [0] * (N+1)
count = 1

for _ in range(M) :
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

def bfs(start) :
    global count

    q = deque([R])
    visited[R] = 1

    while q :
        start = q.popleft()
        graph[start].sort()

        for i in graph[start] :
            if visited[i] == 0 :
                count += 1
                visited[i] = count
                q.append(i)

bfs(R)

for j in visited[1:] :
    print(j)