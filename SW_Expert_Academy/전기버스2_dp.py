T = int(input())
for t in range(1,T+1):
    n, *lst = map(int,input().split())
    lst = [0]+list(lst)
    dp = [100000]*(n+1)
    dp[n]=0
    for idx in range(n-1,0,-1):
        for loc in range( min(n, idx+lst[idx]), idx-1,-1):
            dp[idx] = min(dp[idx],dp[loc]+  (1 if idx > 1 else 0))
    print(f'#{t} {dp[1]}')
    