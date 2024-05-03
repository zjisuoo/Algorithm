N = int(input())
board = [list(map(int, input())) for _ in range(N)]

def dfs(x, y, N) :
    check = board[x][y]
    for i in range(x, x+N) :
        for j in range(y, y+N) :
            if check != board[i][j] :
                check = -1
                break

    if check == -1 :
        print("(", end ="")
        N = N//2
        dfs(x, y, N)
        dfs(x, y+N, N)
        dfs(x+N, y, N)
        dfs(x+N, y+N, N)
        print(")", end="")

    elif check == 1 :
        print(1, end ="")
    else :
        print(0, end ="")

dfs(0, 0, N)
