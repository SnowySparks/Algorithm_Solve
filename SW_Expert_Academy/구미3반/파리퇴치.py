# import sys
# sys.stdin = open('input.txt','r')
from pprint import pprint as print
T = int(input())

for t in range(1, T + 1):
    n, m = map(int,input().split())
    
    lst = [ [0] * (n+1) for _ in range(n+1) ]
    for i in range(1,n+1):
        lst[i][1:] = map(int,input().split())
    
    for row in range(1,n+1):
        for col in range(1,n+1):
            lst[row][col] += lst[row][col-1]

    for col in range(1,n+1):
        for row in range(1,n+1):
            lst[row][col] += lst[row-1][col]
            
    ans = 0
    
    for row in range(m,n+1):
        for col in range(m,n+1):
            ans = max(ans, lst[row][col] - lst[row-m][col] - lst[row][col-m] + lst[row-m][col-m])
    print(f'#{t} {ans}')