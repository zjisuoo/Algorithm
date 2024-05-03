N = int(input())

lines = []

for _ in range(N):
    A, B = map(int, input().split())

    lines.append((A, B))

lines.sort()

# a 전깃줄 번호를 기준으로 오름차순 정렬된 b 전깃줄 번호의 수열
A_to_B = list(map(lambda x: x[1], lines))

# LIS 알고리즘 구현
max_length = [1] * N

for i in range(1, N):
    for j in range(i):
        if A_to_B[i] > A_to_B[j]:
            max_length[i] = max(max_length[i], max_length[j] + 1)

# 없애야 하는 전깃줄의 최소 개수 = 현재 전깃줄의 개수 - 겹치치 않는 최대 전깃줄의 개수
print(N - max(max_length))