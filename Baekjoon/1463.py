X = int(input())
result = [0] * (X + 1)

for i in range (2, X + 1) :
	result[i] = result[i-1] + 1

	if i % 2 == 0 :
		result[i] = min(result[i], result[i//2] + 1)

	if i % 3 == 0 :
		result[i] = min(result[i], result[i//3] + 1)


print(result[X])
