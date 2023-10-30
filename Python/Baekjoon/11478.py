S=input()
count=set()

for i in range(len(S)):
	for j in range(i, len(S)):
		temp=S[i:j+1]
		count.add(temp)

print(len(count))