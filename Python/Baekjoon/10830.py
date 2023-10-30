def mul(N, matrix1 ,matrix2) :
	result = [[0 for _ in range(N)] for _ in range(N)]

	for i in range(N) :
		for j in range(N) :
			for k in range(N) :
				result[i][j] += matrix1[i][k] * matrix2[k][j]
			result[i][j] %= 1000
	return result

def divide(N, B, matrix) :
	if B == 1 :
		return matrix
	elif B == 2 :
		return mul(N, matrix, matrix)
	else :
		tmp = divide(N, B//2, matrix)
		if B % 2 == 0 :
			return mul(N, tmp, tmp)
		else :
			return mul(N, mul(N, tmp, tmp), matrix)

N, B = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]

result = divide(N, B, A)
for row in result :
	for num in row :
		print(num%1000, end = ' ')
	print()
