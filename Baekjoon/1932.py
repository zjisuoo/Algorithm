N = int(input())
result = []

for i in range(N):
    result.append(list(map(int, input().split())))

for i in range (1, N):
    for j in range (i + 1) :
        if j == 0 :
            result[i][0] = result[i][0] + result[i - 1][0]
        elif j == i :
            result[i][j] = result[i][j] + result[i - 1][j - 1]
        else:
            result[i][j] = max(result[i - 1][j - 1], result[i - 1][j]) + result[i][j]

print(max(result[N - 1]))