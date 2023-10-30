import sys

N=int(input())
arr=list(map(int, sys.stdin.readline().rstrip().split()))

arrset=set(arr) #중복 없애기
a=list(arrset)
a.sort()

arrdict={}
for i in range(len(a)):
	arrdict[a[i]]=i

for i in arr:
	print(arrdict[i], end=' ')

#arr = list(map(int, input().split()))


