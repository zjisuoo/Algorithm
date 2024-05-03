from collections import deque

N, K = map(int, input().split())
S = deque([])
for i in range(1, N + 1):
    S.append(i)

print('<', end='')

while S:
    for i in range(K - 1):
        S.append(S[0])
        S.popleft()
    print(S.popleft(), end='')
    if S:
        print(', ', end='')
print('>')