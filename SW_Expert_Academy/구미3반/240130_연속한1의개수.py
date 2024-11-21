T = int(input())
for test in range(1,T+1):
    n = int(input())
    inp = input()
    lst = [0]*n
    lst[0] = 0 if inp[0]=='0' else 1
    ans = 0
    for idx in range(1,n):
        if inp[idx]=='1':
            lst[idx]=lst[idx-1]+1
            ans = max(ans,lst[idx])
        else: lst[idx] = 0
    print(f'#{test} {ans}')
    