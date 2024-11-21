T = int(input())
for t in range(1,T+1):
    n = int(input())
    arr = [0] * 5002
    q = []
    max_val = 0
    for _ in range(n):
        fr, to = map(int,input().split())
        for idx in range(fr,to+1):
            arr[idx]+=1
    p = int(input())
    for _ in range(p):
        q.append(arr[int(input())])
    print(f'#{t}',*q)