
def around_add(lst, r, c, d):
    res = 0
    #행
    for dr in range(r-d,r+d+1):
        nr = r + dr
        if nr < 0 or nr >= n: continue
        res+=lst[nr][c]
    #열
    for dc in range(c-d,c+d+1):
        nc = r + dc
        if nc < 0 or nc >= m: continue
        res+=lst[r][nc]    
    return res
    
T = int(input())
for t in range(1,T+1):
    n, m = map(int,input().split())
    lst = [ list(map(int,input().split())) for _ in range(n)]
    ans = 0
    for i in range(n):
        for k in range(m):
            ans = max(ans,around_add(lst,i,k,lst[i][k])-lst[i][k])
    print(f'#{t} {ans}')