A1, A2 = map(int, input().split())
C = int(input())
N = int(input())

if C-A1>0 :
	if A2/(C-A1) <= N :
		print(1)
	else :
		print(0)

elif C-A1<0 :
	print(0)

else :
	if A2 <= 0 :
		print(1)
	else :
		print(0)
 
'''
	f(n) = 7n + 7, 
	g(n) = n, 
	c = 8, n0 = 1이다.
	f(1) = 14, 
	c × g(1) = 8이므로 O(n) 정의를 만족하지 못한다.

	f(n) = 7n + 7, 
	g(n) = n, 
	c = 8, n0 = 10이다. 
	모든 n ≥ 10에 대하여 
	7n + 7 ≤ 8n 이므로 O(n) 정의를 만족한다.

	'''