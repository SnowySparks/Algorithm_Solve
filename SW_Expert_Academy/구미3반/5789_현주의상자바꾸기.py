T = int(input())
for t in range(1,T+1):
    N, Q = map(int,input().split())
    arr = [0]*(N+1)
    for d in range(Q):
        l, r = map(int,input().split())
        for idx in range(l,r+1):
            arr[idx] = d+1
    print(f'#{t}',*arr[1:])