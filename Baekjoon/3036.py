def gcd(x, y) :
    mod = x % y
    while mod > 0 :
        x = y
        y = mod
        mod = x % y
    return y

N = int(input())
R = list(map(int, input().split()))
for i in range(1, N):
    Rgcd = gcd(R[0], R[i])
    print('{0}/{1}'.format(R[0]//Rgcd, R[i]//Rgcd))