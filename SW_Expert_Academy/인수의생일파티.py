from heapq import heappop, heappush
INF = 10**9
heap = []
d = [INF] * (1000 + 1)
def dijkstra(start : int = 0) -> int:
    for idx in range(N+1):
        d[idx] = INF
    d[start] = 0
    heappush(heap, (0, start))
    
    while heap:
        dist, loc = heappop(heap)
        dist = dist
        
        if d[loc] < dist:
            continue
        
        for cost, nxt in gh[loc]:
            new_dist = dist + cost
            if new_dist < d[nxt]:
                d[nxt] = new_dist
                heappush(heap, (new_dist, nxt))
    

T = int(input())
for tc in range(1, T+1):
    N, M, X= map(int,input().split())
    gh = [ [] for _ in range(N+1)]
    for _ in range(M):
        x, y, c = map(int,input().split())
        gh[x].append((c, y))
    dijkstra(X)
    tohome = d[:]
    ans = 0
    for idx in range(1, N+1):
        if idx == X:
            continue
        dijkstra(idx)
        ans = max(ans, tohome[idx] + d[X])
    print(f'#{tc} {ans}')