T = 10 #total testcase
n = 100 #map size
# import sys
# sys.stdin = open('input.txt','r')
mv = [(0,1),(0,-1),(-1,0)]

for tc in range(1,T+1):
    #input
    tmp = int(input())
    lst = [ list(map(int,input().split())) for _ in range(n) ]
    
    #find end point
    for i in range(100):
        if lst[99][i] == 2:
            r, c = 99, i
            break
        
    #simulation - go to start point
    
    while r > 0 :
        for idx in range(3):
            nr, nc = r + mv[idx][0] , c + mv[idx][1]
            if nr < 0 or nr >= n or nc < 0 or nc >= n or lst[nr][nc]==0 : continue
            lst[nr][nc]=0
            r, c = nr, nc
            break
    print(f'#{tc} {c}')
    
    