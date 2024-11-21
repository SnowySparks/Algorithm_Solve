T = int(input())
for t in range(1,T+1):
    n = int(input())
    lst = sorted(map(int,input().split()))
    a1, a2 = lst[:5] , lst[-1:-6:-1]
    ans = []
    for i, k in zip(a1, a2):
        ans.append(k)
        ans.append(i)
    print(f'#{t}',*ans)
    