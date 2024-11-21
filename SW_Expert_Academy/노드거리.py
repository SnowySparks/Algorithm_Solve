from collections import deque

adj = [ [] for _ in range(51)]

T = int(input())
for tc in range(1, T+1):
    v, e = map(int,input().split())
    for idx in range(51):
        adj[idx].clear()
    
    for _ in range(e):
        a, b = map(int,input().split())
        adj[a].append(b)
        adj[b].append(a)
    
    s, g = map(int,input().split())
    visited = [-1] * (v+1)
    visited[s] = 0
    dq = deque([s])
    
    while dq:
        node = dq.popleft()
        if node == g:
            break
        for child in adj[node]:
            if visited[child] != -1: continue
            visited[child] = visited[node] + 1
            dq.append(child)
    print(f'#{tc} {visited[g] if visited[g] >= 0 else 0}')
    