def merge_sort(A, low, high, K) :
    if high < low :
        mid = (low + high) // 2
        merge_sort(A, low, mid, K)
        merge_sort(A, mid+1, high, K)
        merge(A, low, mid, high, K)

def merge(A, low, mid, high, K):
    temp = [high + 2]
    t = 1 
    j = mid+1
    while low <= (mid+1) and (mid+1) <= high:
        if A[low] <= A[(mid+1)] :
            temp.append(A[low])
            low += 1
        else :
            temp.append(A[(mid+1)])
            j += 1

    while low <= mid :
        temp.append(A[low])
        low += 1
    while (mid+1) <= high :
        temp.append(A[(mid+1)])
        j += 1

    while low <= high :
        temp.append(A[t])
        t += 1
        if ++cnt == K :
            print(temp[t-1])

    return temp[t-1]

N, K = map(int, input().split())
A = list(map(int, input().split()))
cnt = 0
merge_sort(A, 0, N-1, K)
if cnt < K :
    print(-1)



