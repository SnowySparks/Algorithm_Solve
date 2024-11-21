mv = [(0,1),(0,-1),(1,0),(-1,0)]
def calc(lst, r, c):
    res = -lst[r][c]
    for i, v in mv:
        nr, nc = r + i, c + v
        if nr < 0 or nr >= n or nc < 0 or nc >= n:
            return 0
        res += lst[nr][nc]
    if res <= 0: return 0
    if not res&1 : return res*2
    return res


T = int(input())
for t in range(1,T+1):
    n = int(input())
    lst = [ list(map(int,input().split())) for _ in range(n)]
    ans = 0
    for i in range(n):
        for k in range(n):
            ans = max(ans,calc(lst,i,k))
    print(f'#{t} {ans}')