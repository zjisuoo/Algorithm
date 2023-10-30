#for i in range (len(A)-1) :
#	result.append(A[i] + A[i+1])
#	result.append(A[i] + A[i+1] + A[i+2])


#for i in range (N) :
#	re_sum = 0
#	for j in range (i) :
#		re_sum += A[i + j]  
#		result.append(re_sum)

	
#print(max(result))
	
def dynamic_partial_sum(arr):
    cache = [0] * len(arr)
    cache[0] = arr[0]
    for i in range(0, len(arr)):
        cache[i] = max(0, cache[i-1]) + arr[i]
        #print(i, arr[i], cache)
    print(max(cache))
    #return max(cache)

N = int(input())
A = list(map(int, input().split()))

#print("list", A)
dynamic_partial_sum(A)





