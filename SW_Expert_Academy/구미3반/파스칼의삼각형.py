dp = [ [0] * 51 for _ in range(51) ]
dp[1][1] = 1
for idx in range(2,51):
    dp[idx][1] = dp[idx][idx] = 1
    for i in range(2,idx):
        dp[idx][i] = dp[idx-1][i] + dp[idx-1][i-1]

T = int(input())
for tc in range(1,T+1):
    n = int(input())
    print(f'#{tc}')
    for idx in range(1,n+1):
        print(*dp[idx][1:idx+1])