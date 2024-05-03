N = int(input())
A = map(int, input().split())
array = [0]

def binary_search(target, start, end) :
	while start <= end :
		mid = (start+end) // 2

		if array[mid] < target :
			start = mid + 1
		else :
			end = mid - 1
	return start

for i in A :
	if array[-1] < i :
		array.append(i)
	else :
		array[binary_search(i, 0, len(array)-1)] = i

print(len(array)-1)

