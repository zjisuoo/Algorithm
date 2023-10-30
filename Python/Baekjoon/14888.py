N = int(input())
num = list(map(int, input().split()))
op = list(map(int, input().split()))

maxi = -1e9
mini = 1e9

def dfs(depth, total, plus, minus, multi, divine):
    global maxi, mini
    if depth == N:
        maxi = max(total, maxi)
        mini = min(total, mini)
        return

    if plus:
        dfs(depth + 1, total + num[depth], plus - 1, minus, multi, divine)
    if minus:
        dfs(depth + 1, total - num[depth], plus, minus - 1, multi, divine)
    if multi:
        dfs(depth + 1, total * num[depth], plus, minus, multi - 1, divine)
    if divine:
        dfs(depth + 1, int(total / num[depth]), plus, minus, multi, divine - 1)

dfs(1, num[0], op[0], op[1], op[2], op[3])

print(maxi)
print(mini)