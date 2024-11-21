T = int(input())

for test_case in range(1,T+1):
    n, m = map(int,input().split())
    arr = list(map(int,input().split()))
    for i in range(1,n):
        arr[i]+=arr[i-1]
    ans_max, ans_min = arr[m-1], arr[m-1]
    for i in range(m,n):
        ans_max = max(ans_max, arr[i]-arr[i-m])
        ans_min = min(ans_min, arr[i]-arr[i-m])
    print(f'#{test_case} {ans_max - ans_min}')