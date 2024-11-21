
_SET = (1,2,3,4,5,6,7,8,9,10,11,12)

dp = [ [0]* 101 for _ in range(13)]
for i in range( (1<<12)):
    cnt, total = 0, 0
    for j in range(12):
        if i&(1<<j):
            cnt+=1
            total+=_SET[j]
    dp[cnt][total]+=1

T = int(input())
for t in range(1,T+1):
    print(f'#{t} {dp[n][k]}')
    n, k = map(int,input().split())
    
    
    
    
    
    
    
    
    