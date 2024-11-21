dp = [ [0] * 5051 for _ in range(101)]
dp[1][1:101] = [1]*100
for cnt in range(2,101):
    for t_sum in range(1,5051):
        if t_sum - cnt >= 0:
            dp[cnt][t_sum]+=dp[cnt-1][t_sum-cnt]

T = int(input())
for t in range(1,T+1):
    n, k = map(int,input().split())
    print(f'#{t} {dp[n][k]}')