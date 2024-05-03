'''
T = int(input())
G = [int(input()) for _ in range(T)]

m = max(G)
prime = [False, False]+[True]*(m-1)

for i in range(2, int(m**0.5)+1) :
	if prime[i] :
		for j in range(i+1, m+1, i) :
			if prime[j] :
				prime[j] = False

for n in G :
	cnt = 0
	for i in range((n//2)+1) :
		if prime[i] and prime[n-i] :
			cnt += 1
	print(cnt)
'''

import sys

T = int(input())
G = [0]*T
max_G=0

for i in range(T) :
    _=int(sys.stdin.readline())
    G[i]=_

    if max_G <_:
        max_G =_

prime = [True]*(max_G+1)
prime[1] = False

for i in range(2,int(max_G**0.5)+1) :
    if prime[i] :
        for j in range(i+i, max_G+1, i) :
            prime[j]=False

for i in G:
    cnt=0
    for j in range(2,i//2+1):
        if prime[j] and prime[i-j]:
            cnt+=1

    print(cnt)