# import sys
# sys.stdin = open('input.txt','r')

def binary(lst : list, target : int) :
    l, r = 0, n-1
    state = 0
    # state : 직전 탐색방향, -1; 왼쪽, 1 : 오른쪽
    while ( l <= r ):
        mid = (l + r) >> 1
        
        if (lst[mid] == target):
            return True
        
        elif (lst[mid] > target):
            if state == 1:
                return False
            state = 1
            r = mid -1
        else:
            if state == -1:
                return False
            state = -1
            l = mid + 1
    return False
        
T = int(input())
for tc in range(1, T+1):
    n, m = map(int,input().split())
    lst = sorted(map(int,input().split())) # 원소 리스트
    mlst = list(map(int,input().split())) # 찾을 것 리스트
    
    cnt = 0
    for val in mlst:
        cnt += 1 if binary(lst, val) else 0
    print(f'#{tc} {cnt}')
    
    