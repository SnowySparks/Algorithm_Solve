from collections import deque
MAX_VAL = 1000000
T = int(input())
for tc in range(1, T+1):
    N, M = map(int,input().split())
    v = [-1] * (MAX_VAL + 1)
    v[N] = 0
    dq = deque([N])
    while dq:
        loc = dq.popleft()
        if loc == M:
            break
        
        nxt = loc + 1
        if nxt <= MAX_VAL and v[nxt] == -1:
            v[nxt] = v[loc] + 1
            dq.append(nxt)

        nxt = loc - 1
        if nxt >= 1 and v[nxt] == -1:
            v[nxt] = v[loc] + 1
            dq.append(nxt)
            
        nxt = loc - 10
        if nxt >= 1 and v[nxt] == -1:
            v[nxt] = v[loc] + 1
            dq.append(nxt)
            
        nxt = loc * 2
        if nxt <= MAX_VAL and v[nxt] == -1:
            v[nxt] = v[loc] + 1
            dq.append(nxt)
    
    print(f'#{tc} {v[M]}')