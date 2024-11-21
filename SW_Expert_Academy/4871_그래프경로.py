from collections import deque
T = int(input())

for tc in range(1,T+1):
    V, E = map(int,input().split())
    gh = [ [] for _ in range(V+1) ]
    for _ in range(E):
        fr, to = map(int,input().split())
        gh[fr].append(to)
    S, G = map(int,input().split())
    
    dq = deque()
    dq.append(S)
    found = False
    
    while dq:
        loc = dq.popleft()
        if loc == G:
            found = True
            break
        for child in gh[loc]:
            dq.append(child)
    
    print(f'#{tc} { 1 if found else 0}')
    