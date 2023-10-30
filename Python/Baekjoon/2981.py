import sys

def gcd(x, y):
    mod = x % y
    while mod > 0:
        x = y
        y = mod
        mod = x % y
    return y

N = int(input())
Mlist = [] 
result =[]

for i in range(N) :
	Mlist.append(int(sys.stdin.readline()))

# 모든 A-B, B-C ...
Mgcd = [abs(Mlist[1] - Mlist[0])]

for j in range(2, len(Mlist)) :
	Mgcd.append(gcd(abs(Mlist[j] - Mlist[j - 1]), Mgcd[0]))

Mgcd.sort()

for k in range(1, int(Mgcd[0] ** 0.5) + 1) :
    if Mgcd[0] % k == 0 :
        result.append(k)
        result.append(Mgcd[0] // k)

result = list(set(result))
result.sort()

for l in result[1 : ] :
    print(l, end=" ")
