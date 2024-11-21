from collections import deque
MAX_VAL = 10**9

mv = [(-1, 0), (1, 0), (0, 1), (0, -1)]

T = int(input())
for tc in range(1, T + 1):
    n = int(input())
    lst = [ list(map(int,input().split())) for _ in range(n)]
    dq = deque()
    ans = MAX_VAL
    dp = [ [MAX_VAL] * n for _ in range(n)]
    
    dp[0][0] = lst[0][0]
    
    dq.append((0, 0))
    while dq:
        r, c = dq.popleft()
        for dr, dc in mv:
            nr, nc = r + dr, c + dc
            if nr < 0 or nr >= n or nc < 0 or nc >= n:
                continue
            if dp[nr][nc] > dp[r][c] + lst[nr][nc]:
                dp[nr][nc] = dp[r][c] + lst[nr][nc]
                dq.append((nr, nc))
    print(f'#{tc} {dp[n-1][n-1]}')