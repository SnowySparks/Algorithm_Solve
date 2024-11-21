# import sys
# # sys.stdin = open('input.txt','r')
res = []

def calmax(r, c, depth = 0, total = 0, amount = 0) -> int:
    if depth == 0 and dp[r][c] != 0:
        return dp[r][c]
    if total > C:
        return 0
    if depth == M:
        return amount

    if depth == 0:
        dp[r][c] = max(calmax(r,c+1,depth+1,total + lst[r][c], amount + lst[r][c]**2), \
            calmax(r,c+1,depth+1,total,amount))
        return dp[r][c]
        
    return max(calmax(r,c+1,depth+1,total + lst[r][c], amount + lst[r][c]**2), \
        calmax(r,c+1,depth+1,total,amount))

def dfs(sr, sc, cnt):
    global ans 
    if cnt == 2:
        ans = max(ans, calmax(*res[0]) + calmax(*res[1]))
        return
    
    for r in range(sr, N):
        if r == sr:
            for c in range(sc, N-M+1):
                res.append((r, c))
                dfs(r, c+M, cnt+1)
                res.pop()
        else:
            for c in range(N-M+1):
                res.append((r, c))
                dfs(r, c+M, cnt+1)
                res.pop()
    return
                 

T = int(input())
for tc in range(1, T + 1):
    N, M, C = map(int,input().split())
    ans = 0
    lst = [ list(map(int,input().split())) for _ in range(N)]
    dp = [ [] * (N+1) for _ in range(N+1)]
    dfs(0, 0, 0)
    print(f'#{tc} {ans}')
    