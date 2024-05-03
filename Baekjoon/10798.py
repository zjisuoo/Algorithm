A = [[0] * 15 for i in range(5)]

for i in range(5):
    B = list(input())
    B_len = len(B)
    for j in range(B_len):
        A[i][j] = B[j]
for i in range(15):
    for j in range(5):
        if A[j][i] == 0:
            continue;
        else:
            print(A[j][i], end='')