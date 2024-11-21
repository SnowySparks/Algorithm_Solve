T = int(input())
for test_case in range(1, T + 1):
    n = int(input())
    lst = list(map(int,input().split()))
    ans = 0
    max_val = lst[-1]
    for idx in range(n-2,-1,-1):
        if max_val >= lst[idx]:
            ans+=(max_val - lst[idx])
        else:
            max_val = lst[idx]
    print(f'#{test_case} {ans}')