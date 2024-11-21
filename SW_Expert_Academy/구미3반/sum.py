T = 10
for t in range(1,T+1):
    tc = int(input())
    lst = [ list(map(int,input().split())) for _ in range(100)]
    ans = sum(lst[0])
    #가로방향
    for row in range(1,100):
        ans = max(ans,sum(lst[row]))
    
    #세로방향
    for col in range(0,100):
        total = 0
        for row in range(0,100): 
            total+=lst[row][col]
        ans = max(ans,total)
    
    #대각선방향
    total = 0
    for i in range(100):
        total += lst[i][i]
    ans = max(ans,total)
    
    total = 0
    for i in range(100):
        total += lst[i][99-i]
    ans = max(ans,total)
    
    print(f'#{tc} {ans}')