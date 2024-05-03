while True:
    N = int(input())
    if N == -1: # 입력 값이 -1이면 반복문 종료
        break;
    A = []
    for i in range(1, N) :
        if N % i == 0 :
            A.append(i)
    if sum(A) == N :
        print(N, " = ", " + ".join(str(i) for i in A), sep="")
    else:
        print(N, "is NOT perfect.")