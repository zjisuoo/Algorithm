import sys

T = int(input())

for i in range(T):
    A, B = map(int,sys.stdin.readline().split())
    a, b= A, B

    while A % B != 0 :
        A, B = B, A % B

    print(a * b // B)
