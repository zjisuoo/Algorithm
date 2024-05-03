nums = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'

N, B = map(int,input().split())
ans = ''

while N :
    ans = nums[N % B] + ans
    N //= B

print(ans)