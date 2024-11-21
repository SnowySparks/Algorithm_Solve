from heapq import heappop, heappush
INF = 10**11
heap = []

def dijkstra(start : int = 0) -> int:
    d = [INF] * (N + 1)
    d[start] = 0
    heappush(heap, (0, start))
    
    while heap:
        dist, loc = heappop(heap)
        dist = -dist
        
        if d[loc] < dist:
            continue
        
        for cost, nxt in gh[loc]:
            new_dist = dist + cost
            if new_dist < d[nxt]:
                d[nxt] = new_dist
                heappush(heap, (-new_dist, nxt))
    return d[N]
    
T = int(input())
for tc in range(1, T+1):
    N, E = map(int,input().split())
    gh = [ [] for _ in range(N+1)]
    for _ in range(E):
        s, e, w = map(int,input().split())
        gh[s].append((w, e))
    print(f'#{tc} {dijkstra()}')