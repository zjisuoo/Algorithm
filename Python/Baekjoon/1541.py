S = input().split('-')

A = 0

for i in S[0].split('+') :
	A += int(i)

for i in S[1:] :
	for j in i.split('+') :
		A -= int(j)

print(A)