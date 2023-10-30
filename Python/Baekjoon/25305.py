def sol(score, k):
    score.sort(reverse = True)
    print(score[k - 1])
 
N, k=map(int, input().split())
score = list(map(int, input().split()))
sol(score, k)
