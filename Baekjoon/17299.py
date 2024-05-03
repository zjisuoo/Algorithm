from collections import Counter
from sys import stdin

N = int(stdin.readline())
nums = list(map(int, stdin.readline().split()))
nums_count = Counter(nums)
result = [-1] * N
stack = [0]

for i in range(1, N):
    while stack and nums_count[nums[stack[-1]]] < nums_count[nums[i]]:
            result[stack.pop()] = nums[i]
    stack.append(i)

print(*result)