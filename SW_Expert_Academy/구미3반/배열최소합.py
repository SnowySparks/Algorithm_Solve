# import sys
# sys.stdin = open('input.txt','r')
T = int(input())

def tsp(cnt, state) -> int:
    if cnt == n:
        return 0
    
    if dp[state] != -1:
        return dp[state]
    
    dp[state] = 10**9
    for idx in range(n):
        if state & (1<<idx) != 0:
            continue
        dp[state] = min(dp[state], tsp(cnt+1, state | (1<<idx) )+ arr[cnt][idx] )
    return dp[state]
        

for tc in range(1, T+1):
    n = int(input())
    arr = [list(map(int,input().split())) for _ in range(n)]
    dp =  [-1] * (1<<n)
    print(f'#{tc} {tsp(0,0)}')
    