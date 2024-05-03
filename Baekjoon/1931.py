N = int(input())
T = []

for i in range(N):
    start, end = map(int, input().split())
    T.append([start, end])
T = sorted(T, key=lambda a: a[0])
T = sorted(T, key=lambda a: a[1])
end_time = 0
cnt = 0
for i, j in T:
    if i >= end_time:
        cnt += 1
        end_time = j
print(cnt)