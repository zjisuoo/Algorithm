import sys
from collections import deque

N = int(sys.stdin.readline())
queue = deque()
while 1 :
    n = int(sys.stdin.readline())
    if n == -1 :
        break
    if n != 0 and len(queue) < N :
        queue.append(n)
    elif n == 0 :
        queue.popleft()
if queue :
    print(*queue)
else : 
    print("empty")