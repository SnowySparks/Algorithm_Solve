from collections import deque
mv = [(1, 0), (-1, 0), (0, 1), (0, -1)]
T = int(input())
for tc in range(1, T+1):
    n = int(input())
    lst = [input() for _ in range(n)]
    
    for r in range(n):
        for c in range(n):
            if lst[r][c] =='2':
                st = (r, c,)
            elif lst[r][c] =='3':
                en = (r, c,)
    
    
    v = [[-1] * n for _ in range(n)]
    v[st[0]][st[1]] = 0
    dq =deque()
    dq.append(st)
    
    while dq:
        r, c = dq.popleft()
        if (r, c,) == en:
            break
        for dr, dc in mv:
            nr , nc = r + dr, c + dc
            if nr < 0 or nr >=n or nc < 0 or nc >=n or v[nr][nc] != -1 or lst[nr][nc] =='1':
                continue
            v[nr][nc] = v[r][c] + 1
            dq.append((nr, nc,))
    print(f'#{tc} {v[en[0]][en[1]]-1 if v[en[0]][en[1]] != -1 else 0}')
    