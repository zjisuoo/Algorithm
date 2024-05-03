num=int(input())
d=2

while num!=1:
	if num%d!=0:
		d+=1
	else:
		num//=d
		print(d)
