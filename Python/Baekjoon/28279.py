#1 X: 정수 X를 덱의 앞에 넣는다. (1 ≤ X ≤ 100,000)
#2 X: 정수 X를 덱의 뒤에 넣는다. (1 ≤ X ≤ 100,000)
#3: 덱에 정수가 있다면 맨 앞의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
#4: 덱에 정수가 있다면 맨 뒤의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
#5: 덱에 들어있는 정수의 개수를 출력한다.
#6: 덱이 비어있으면 1, 아니면 0을 출력한다.
#7: 덱에 정수가 있다면 맨 앞의 정수를 출력한다. 없다면 -1을 대신 출력한다.
#8: 덱에 정수가 있다면 맨 뒤의 정수를 출력한다. 없다면 -1을 대신 출력한다.

import sys
input = sys.stdin.readline
from collections import deque

N = int(input())
d = deque()

for _ in range(N) :
	l = list(map(int, input().strip().split()))
	command = l[0]
	cnt = len(d)

	if command == 1 :
		d.appendleft(l[1])
	elif command == 2 :
		d.append(l[1])
	elif command == 3 :
		print(d.popleft() if cnt else -1)
	elif command == 4 :
		print(d.pop() if cnt else -1)
	elif command == 5 :
		print(len(d))
	elif command == 6 :
		print(0 if cnt else 1)
	elif command == 7 :
		print(d[0] if cnt else -1)
	elif command == 8 :
		print(d[-1] if cnt else -1)





