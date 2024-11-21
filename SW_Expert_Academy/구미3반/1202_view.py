T = 10
for t in range(1,T+1):
    n = int(input())
    lst = list(map(int,input().split()))
    cnt = 0
    for idx in range(2,n-2):
        length = 1001
        for dr in range(-2,3,1):
            if dr == 0: continue
            length = min(length,lst[idx]-lst[idx-dr])
        if 0 < length <= 1000:
            cnt+=length       
    print(f'#{t} {cnt}')