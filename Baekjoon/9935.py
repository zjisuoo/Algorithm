N = input()
M = input()

stack = []

for i in N :
	stack.append(i)
	if i == stack[-1] and ''.join(stack[-len(M):]) == M :
		del stack[-len(M):]

result = ''.join(stack)

if result == '' :
	print('FRULA')
else :
	print(result)