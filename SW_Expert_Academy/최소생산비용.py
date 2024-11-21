INF = 10** 9
def tsp(loc : int, state : int) -> int:
    if loc == n:
        return 0
    if dp[state] != -1:
        return dp[state]
    dp[state] = INF
    for idx in range(n):
        if state & (1<<idx): continue
        dp[state] = min(dp[state], tsp(loc +1, state | (1<<idx)) + lst[loc][idx])
    return dp[state]

T = int(input())
for tc in range(1, T+1):
    n = int(input())
    lst = [ list(map(int, input().split())) for _ in range(n)]
    dp = [-1] * (1 << n)
    print(f'#{tc} {tsp(0, 0)}')
    