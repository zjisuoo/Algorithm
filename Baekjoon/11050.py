from math import factorial

N, K = map(int, input().split())
result = factorial(N) // (factorial(K) * factorial(N - K))
print(result)