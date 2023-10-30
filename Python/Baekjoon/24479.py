import sys
sys.setrecursionlimit(10**9)
# 재귀최대깊이설정
input = sys.stdin.readline

N, M, R = map(int, input().split())
graph = [[] for _ in range(N+1)]
visited = [0] * (N+1)
cnt = 1

for _ in range(M) :
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

def dfs(start) :
    global cnt 
    visited[start] = cnt
    graph[start].sort()
    
    for i in graph[start] :
        if visited[i] == 0 :
            cnt += 1
            dfs(i)

dfs(R)

for j in range(1, N+1) :
    print(visited[j])

