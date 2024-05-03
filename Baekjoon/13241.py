A, B = map(int, input().split())

'''
for i in range(max(A, B), (A*B)+1) :
	if i%A == 0 and i % B == 0 :
		print(i)
		break
'''

def GCD(x, y) :
	while y > 0 :
		x, y = y, x % y
	return x


def LCM(x, y) :
	return x * y//GCD(x, y)

print(LCM(A, B))
