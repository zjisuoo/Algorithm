A, B, C = map(int, input().split())

if A + B + C == 180 :
	if A and B and C == 60 :
		print('Equilateral')

	elif A == B or B == C or A == C :
		print('Isosceles')

	else :
		print('Scalene')

else :
	print('Error')
