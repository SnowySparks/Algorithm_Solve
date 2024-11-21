T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.

def lower_bound(loc, val):
    st,en = 0, len(loc)
    while st< en:
        mid = (st+en)//2
        if loc[mid] >= val:
            en=mid
        else:
            st=mid+1
    return en

for test_case in range(1, T + 1):
    n = int(input())
    arr = list(map(int,input().split()))
    lst = []
    for i in range(n):
        if not lst or lst[-1] < arr[i]: lst.append(arr[i])
        else:
            loc = lower_bound(lst,arr[i])
            lst[loc]=arr[i]
    print(f'#{test_case} {n - len(lst)}')