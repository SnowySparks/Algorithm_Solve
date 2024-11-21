from itertools import combinations
num = [1,2,3,4,5,6,7,8,9,10,11,12]

T = int(input())
for t in range(1,T+1):
    n, k = map(int,input().split())
    cnt = 0
    for res in combinations(range(1,13),n):
        if sum(res)==k: cnt+=1
    print(f'#{t} {cnt}')
    