N = int(input())

def recursive(x, y, n):
    flag = False

    for i in range(x, x + n):
        if flag:
            break

        for j in range(y, y + n):
            if paper[x][y] != paper[i][j]:
                recursive(x, y, n // 2)
                recursive(x, y + n // 2, n // 2)
                recursive(x + n // 2, y, n // 2)
                recursive(x + n // 2, y + n // 2, n // 2)

                flag = True
                break

    if not flag:
        if paper[x][y] == 0:
            count[0] += 1
        else:
            count[1] += 1


paper = []
for i in range(N):
    paper.append(list(map(int, input().split())))

count = [0, 0]

recursive(0, 0, N)
for i in count:
    print(i)