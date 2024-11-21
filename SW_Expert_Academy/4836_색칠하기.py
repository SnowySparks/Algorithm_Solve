# import sys
# sys.stdin = open('input.txt','r')
# from pprint import pprint as print

T = int(input())

for t in range(1, T + 1):
    mp = [ [0] * 11 for _ in range(11)]
    q = int(input())
    for _ in range(q):
        x1, y1, x2, y2, color = map(int,input().split())
        mp[x1][y1]+=color
        mp[x2+1][y1]-=color
        mp[x1][y2+1]-=color
        mp[x2+1][y2+1]+=color
        
    for row in range(0,11):
        for col in range(1,11):
            mp[row][col]+=mp[row][col-1]
    
    for col in range(0,11):
        for row in range(1,11):
            mp[row][col]+=mp[row-1][col]
    
    cnt = 0
    for row in range(10):
        for col in range(10):
            if mp[row][col]==3: cnt+=1
    
    print(f'#{t} {cnt}')