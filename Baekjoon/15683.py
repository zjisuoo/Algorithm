import copy

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

direction = [[], 
[[0], [1], [2], [3]], 
[[0, 2], [1, 3]], 
[[0, 1], [1, 2], [2, 3], [0, 3]],
[[0, 1, 2], [0, 1, 3], [1, 2, 3], [0, 2, 3]], 
[[0, 1, 2, 3]]]

N, M = map(int, input().split())
office = []
cctv = []

for i in range(N):
    data = list(map(int, input().split()))
    office.append(data)
    for j in range(M):
        if data[j] in [1, 2, 3, 4, 5]:
            cctv.append([data[j], i, j])

def fill(office, mm, x, y) :
    for i in mm:
        nx = x
        ny = y
        while True:
            nx += dx[i]
            ny += dy[i]
            if nx < 0 or ny < 0 or nx >= N or ny >= M:
                break
            if office[nx][ny] == 6:
                break
            elif office[nx][ny] == 0:
                office[nx][ny] = '#'

def dfs(depth, arr):
    global result

    if depth == len(cctv):
        count = 0
        for i in range(N):
            count += arr[i].count(0)
        result = min(result, count)
        return

    temp = copy.deepcopy(arr)
    cctv_num, x, y = cctv[depth]

    for i in direction[cctv_num]:
        fill(temp, i, x, y)
        dfs(depth+1, temp)
        temp = copy.deepcopy(arr)
        print(temp)


result = int(1e9)
dfs(0, office)
print(result)


