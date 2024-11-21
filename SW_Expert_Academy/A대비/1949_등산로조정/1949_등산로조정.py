T = int(input())
mv = [(1, 0), (-1, 0), (0, -1), (0, 1)]

def dfs(r : int, c : int, used : bool) -> int:
    cnt = 1
    v[r][c] = True
    for dr, dc in mv:
        nr, nc = r + dr, c +dc
        if nr < 0 or nc < 0 or nr >= n or nc >= n:
            continue
        if v[nr][nc]: continue
        if lst[nr][nc] < lst[r][c]:
            cnt = max(cnt, dfs(nr, nc, used)+1)
        elif not used and lst[nr][nc] - k < lst[r][c]:
            temp = lst[nr][nc]
            lst[nr][nc] = lst[r][c]-1
            cnt = max(cnt, dfs(nr, nc, True)+1)
            lst[nr][nc] = temp
    v[r][c] = False
    return cnt


for tc in range(1, T+1):
    n, k = map(int,input().split())
    lst = [list(map(int,input().split())) for _ in range(n)]
    v = [[False] * n for _ in range(n)]
    max_height = 0
    for d in lst:
        max_height = max(max_height, max(d))
    ans = 0
    for r in range(n):
        for c in range(n):
            if lst[r][c] == max_height:
                ans = max(ans, dfs(r, c, False))
    print(f'#{tc} {ans}')