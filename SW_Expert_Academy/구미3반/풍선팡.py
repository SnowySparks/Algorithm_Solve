
def around_add(lst, r, c, d):
    res = 0
    #행
    for dr in range(r-d,r+d+1):
        if dr < 0 or dr >= n: continue
        res+=lst[dr][c]
    #열
    for dc in range(c-d,c+d+1):
        if dc < 0 or dc >= m: continue
        res+=lst[r][dc]    
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