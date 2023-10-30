import sys
from collections import deque

N = int(sys.stdin.readline())
Q = deque([])

for i in range(N):
    S = sys.stdin.readline().split()
    if S[0] == 'push':
        Q.append(S[1])
    elif S[0] == 'pop':
        if not Q :
            print(-1)
        else:
            print(Q.popleft())
    elif S[0] == 'size':
        print(len(Q))
    elif S[0] == 'empty':
        if not Q :
            print(1)
        else:
            print(0)
    elif S[0] == 'front':
        if not Q : 
            print(-1)
        else:
            print(Q[0])
    elif Q[0] == 'back':
        if not Q :
            print(-1)
        else:
            print(Q[-1])

#push X: 정수 X를 큐에 넣는 연산이다.
#pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
#size: 큐에 들어있는 정수의 개수를 출력한다.
#empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
#front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
#back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.