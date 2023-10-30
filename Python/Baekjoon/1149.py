N = int(input())
P = []

for i in range(N):
    P.append(list(map(int, input().split())))
    
for i in range(1, len(P)):
    P[i][0] = min(P[i - 1][1], P[i - 1][2]) + P[i][0]
    P[i][1] = min(P[i - 1][0], P[i - 1][2]) + P[i][1]
    P[i][2] = min(P[i - 1][0], P[i - 1][1]) + P[i][2]
print(min(P[N - 1][0], P[N - 1][1], P[N - 1][2]))
