from collections import deque
T = int(input())
for tc in range(1, T+1):
    N, M, K = map(int,input().split())
    lst = deque( sorted(map(int,input().split())) )
    ispossible = True
    threshold = 0
    while lst:
        threshold += M
        for _ in range(K):
            if not lst: break
            
            if lst[0] >= threshold:
                lst.popleft()
            else:
                ispossible = False
                break
        if not ispossible:
            break
    print(f'#{tc} {"Possible" if ispossible else "Impossible"}')