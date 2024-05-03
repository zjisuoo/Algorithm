import sys
input=sys.stdin.readline

N, M = map(int, input().split())
cnt = 0

S = {input().strip() for _ in range(N)}

for j in range(M):
    if input().strip() in S:cnt+=1
    
print(cnt)