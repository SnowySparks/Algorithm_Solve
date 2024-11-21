T = int(input())
dp = [0] * 31
dp[1] = 1
dp[2] = 3
for idx in range(3,31):
    dp[idx] = dp[idx-2]*2 + dp[idx-1]

for tc in range(1,T+1):
    print(f'#{tc} {dp[int(input())//10]}')