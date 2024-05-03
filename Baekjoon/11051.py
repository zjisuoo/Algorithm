from math import factorial

N, K = map(int, input().split())
M = factorial(N) // (factorial(K) * factorial(N - K))
result = M % 10007

print(result)