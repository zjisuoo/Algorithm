import sys
input = sys.stdin.readline
sys.maxsize

N, M, K = map(int, input().split())
board = [list(input()) for _ in range(N)]
prefix = [[0] * (M+1) for _ in range (N+1)]

for i in range(N) :
	for j in range(M) :
		index1 = 0
		index2 = 0
		if (i+j) % 2 == 0 :
			if board[i][j] != 'B' :
				index1 = index1 + 1
			if board[i][j] != 'W' :
				index2 = index2 + 1
		else :
			if board[i][j] == 'B' :
				index1 = index1 + 1
			if board[i][j] == 'W' :
				index2 = index2 + 1

		prefix.append(index1)
		prefix.append(index2)
		prefix[i+1][j+1] = prefix[i][j+1] + prefix[i+1][j] - prefix[i][j]

count = sys.maxsize

for i in range(1, N-K+2) :
	for j in range(1, M-K+2) :
		count = min(count, prefix[i+K-1][j+K-1] - prefix[i+K-1][j-1] - prefix[i-1][j+K-1] + prefix[i-1][j-1])

print(count)

