N=int(input())
card=sorted(map(int,input().split()))
M=int(input())
check=list(map(int, input().split()))
result=[]

def binary(i, card, start, end):
    mid=(start+end)//2
    if start>end:
        result.append(str(0))
    elif i==card[mid]:
        result.append(str(1))
    elif i>card[mid]:
        binary(i, card, mid+1, end)
    else:
        binary(i, card, start, mid-1)

for i in check:
	start=0
	end=len(card)-1
	binary(i, card, start, end)

print(' '.join(result))


#re=[x for i in check for x in card if i==x]

#print(re)

#same=[i for i, j in zip(card, check) if i==j]

#print(same)

