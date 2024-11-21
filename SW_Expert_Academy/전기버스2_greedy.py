from heapq import heappush, heappop
T = int(input())
for tc in range(1, T+1):
    lst = list(map(int, input().split()))
    n = lst[0]
    cnt = 0
    idx = 2
    d = 1 + lst[1]
    heap = []
    while d < n:
        while idx < n and d >= idx:
            heappush(heap, -lst[idx] - idx)
            idx += 1
        cnt += 1
        # print(idx)
        d = (-heap[0])
        heappop(heap)
    
    print(f'#{tc} {cnt}')