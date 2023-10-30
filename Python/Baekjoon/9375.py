from collections import Counter

T = int(input())

for i in range(T) :
    N = int(input())
    wear = []
    for j in range(N) :
        A, B = input().split()
        wear.append(B)
    
    result = Counter(wear)
    cnt = 1 
    for key in result :
        cnt *= result[key] + 1

    print(cnt - 1)


