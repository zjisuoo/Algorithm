def five_count(n) :
	count = 0
	while n != 0 :
		n //= 5
		count += n
	return count

N = int(input())
print(five_count(N))
