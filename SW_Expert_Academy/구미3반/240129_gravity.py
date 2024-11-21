T = int(input())
for test_case in range(1, T + 1):
    n = int(input())
    ans = 0
    arr = list(map(int,input().split()))
    for i in range(n):
        cnt = 0
        for k in range(i+1,n):
            if arr[i] > arr[k]:
                cnt+=1
                if ans < cnt: ans = cnt
    print(f'#{test_case} {ans}')