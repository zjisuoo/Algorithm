import sys

def checkRow(x, n) :
	for i in range(9) :
		if n == sudoku[x][i] :
			return False
	return True

def checkCol(y, n) :
	for i in range(9) :
		if n == sudoku[i][y] :
			return False
	return True

def checkRect(x, y, n) :
	nx = x // 3 * 3
	ny = y // 3 * 3
	for i in range(3) :
		for j in range(3) :
			if n == sudoku[nx+i][ny+j] :
				return False
	return True

def sol(n) :
	if n == len(empty) :
		for _ in range(9) :
			print(*sudoku[_])
		exit(0)

	for i in range(1, 10) :
		x = empty[n][0]
		y = empty[n][1]

		if checkRow(x, i) and checkCol(y, i) and checkRect(x, y, i) :
			sudoku[x][y] = i
			sol(n+1)
			sudoku[x][y] = 0

sudoku = []
empty = []

for i in range(9) :
	sudoku.append(list(map(int, sys.stdin.readline().split())))
	for j in range(9) :
		if sudoku[i][j] == 0 :
			empty.append([i, j])

sol(0)













