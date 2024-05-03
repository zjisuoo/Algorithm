N = int(input())
divisor = list(map(int, input().split()))

max_divisor = max(divisor)
min_divisor = min(divisor)

print(max_divisor * min_divisor)

