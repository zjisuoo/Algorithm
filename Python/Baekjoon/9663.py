def queen(x, X) :
	global result

	if x == X :
		result += 1
		return

	else :
		for i in range(X) :
			chess[x] = i

			for j in range(x) :
				if chess[j] == chess[x] or (chess[x] - x) == (chess[j] - j) or (chess[x] + x) == (chess[j] + j) :
					break

			else : queen(x+1, X) 


N = int(input())

result = 0
chess = [300] * N

queen(0, N)

print(result)