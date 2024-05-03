#분수 A/B는 분자가 A, 분모가 B인 분수를 의미한다. A와 B는 모두 자연수라고 하자.

A1, B1 = map(int, input().split())
A2, B2 = map(int, input().split())


def GCD(x, y) :
	while y > 0 :
		x, y = y, x % y
	return x

def LCM(x, y) :
	return x * y//GCD(x, y)

def sol(a1, b1, a2, b2) :
	answer = []

	down_lcm = LCM(x=b1, y=b2)

	answer_up = a1*(down_lcm//b1) + a2*(down_lcm//b2)
	answer_down = down_lcm
	up_down_gcd = GCD(x=answer_up, y=answer_down)

	answer = [answer_up//up_down_gcd, answer_down//up_down_gcd]
	answer_list = str(answer)[1:-1]
	answer_final = answer_list.replace(',' ,"")

	return answer_final

print(sol(A1, B1, A2, B2))
