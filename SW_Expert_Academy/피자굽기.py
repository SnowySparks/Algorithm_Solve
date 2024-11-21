from collections import deque
T = int(input())
for tc in range(1, T+1):
    N, M = map(int,input().split())
    lst = list(map(int,input().split()))
    dq = deque()
    
    for i, v in enumerate(lst):
        if i == N:
            break
        dq.append([i+1, v])
    
    idx = N 
    while len(dq) > 1:
        num, cheese = dq.popleft()
        cheese//=2
        if cheese > 0:
            dq.append((num, cheese))
        else: #cheese zero
            if idx < M:
                dq.append((idx+1, lst[idx]))
                idx+=1
    print(f'#{tc} {dq[0][0]}')
    