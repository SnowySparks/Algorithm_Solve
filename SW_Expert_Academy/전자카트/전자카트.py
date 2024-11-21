MAX_VAL = 10**8
def dfs(now : int, state : int) -> int: #현재 now 도시에 있고 now포함 방문도시 상태가 state인 경우
    if state == (1<<n) -1: #모든 도시 루프 다돔
        if lst[now][0] == 0: return MAX_VAL
        return lst[now][0]
    
    if dp[now][state] != -1: #dp조건
        return dp[now][state]
    
    dp[now][state] = MAX_VAL
    for idx in range(1, n): #
        if state & (1<<idx) or now == idx:
            continue
        dp[now][state] = min(dp[now][state], dfs(idx, state | (1<<idx)) + lst[now][idx])
    return dp[now][state]

T = int(input())
for tc in range(1, T + 1):
    n = int(input())
    lst = [ list(map(int,input().split())) for _ in range(n)]
    dp = [ [-1] * (1<<n) for _ in range(n)]
    print(f'#{tc} {dfs(0, 1)}') #0번 도시는 이미 방문했다고 가정함.