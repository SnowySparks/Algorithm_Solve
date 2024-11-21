def binary(target, l, r):
    cnt = 0
    while l < r:
        m = (l + r) >> 1
        if m == target: break
        cnt+=1
        if target > m:
            l = m
        else:
            r = m
    return cnt

T = int(input())

for t in range(1,T+1):
    P, a, b = map(int,input().split())
    a_res = binary(a,1,P)
    b_res = binary(b,1,P)
    
    if a_res < b_res : result = 'A'
    elif b_res < a_res : result = 'B'
    else: result = '0'
    print(f'#{t} {result}')
    