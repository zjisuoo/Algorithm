A = list(input())
B = list(input())

a = len(A)
b = len(B)

lcs = [[0] * (b+1) for i in range(a+1)]

for i in range(a) :
    for j in range(b) :
        if A[i] == B[j] :
            lcs[i+1][j+1] = lcs[i][j] + 1
        else:
            lcs[i+1][j+1] = max(lcs[i][j+1], lcs[i+1][j])
                        
print(lcs[a][b])



