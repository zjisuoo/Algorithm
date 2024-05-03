N = int(input())

board = [list(map(int, input().split()))for _ in range(N)]

result_minus = 0
result_zero = 0
result_plus = 0

def dfs(x, y, N) :
	global result_minus, result_zero, result_plus

	num = board[x][y]
	for i in range(x, x+N) :
		for j in range(y, y+N) :
			if (board[i][j] != num) :
				for k in range(3) :
					for l in range(3) :
						dfs(x+k*N//3, y+l*N//3, N//3)
				return

	if num == -1 :
		result_minus += 1
	elif num == 0 :
		result_zero += 1
	else :
		result_plus += 1

dfs(0, 0, N)
print(f'{result_minus}\n{result_zero}\n{result_plus}')