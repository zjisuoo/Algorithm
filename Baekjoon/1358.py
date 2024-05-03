import sys
input = sys.stdin.readline

W, H, X, Y, P = map(int, input().split())
count = 0

for _ in range(P) :
    x, y = map(int, input().split())

    #직사각형 안(선도 포함)
    if (X <= x <= X+W) and (Y <= y <= Y+H) :
        count += 1
        continue

    #반원 안(선도 포함)
    radius = H/2
    semi_l = ((x-X)**2 + (y-(Y+radius))**2)**0.5
    semi_r = ((x-(X+W))**2 + (y-(Y+radius))**2)**0.5

    if semi_l <= radius or semi_r <= radius :
        count += 1 

print(count)






