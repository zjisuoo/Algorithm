def GCD(x, y) :
	while y > 0 :
		x, y = y, x % y
	return x

def LCM(x, y) :
	return x * y//GCD(x, y)

N = int(input())
T = [int(input()) for _ in range(N)]

G = [] # 나무 간격
for i in range(1, N) : 
    G.append(T[i] - T[i - 1])

set_G = list(set(G))  

gcd = set_G[0]
for i in range(1, len(set_G)) :  # 나무 간격 최대공약수
    gcd = GCD(gcd, set_G[i])

answer_tree_cnt = 0
for gap in G : 
    answer_tree_cnt += gap // gcd - 1

print(answer_tree_cnt)