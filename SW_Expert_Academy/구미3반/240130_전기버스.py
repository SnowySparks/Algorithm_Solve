from bisect import bisect_left

T = int(input())
for t in range(1,T+1):
    k, n, m = map(int,input().split())
    cnt = 0 #충전횟수
    now_loc = 0 #현재 버스 위치
    now_loc_charge = -1 #현재 충전소 위치의 인덱스값
    charge = list(map(int,input().split())) #충전소 위치 리스트
     
    while now_loc + k < n: #종료조건 - 이게 아닌경우 바로 n으로 갈수 있기 때문
        loc = bisect_left(charge,now_loc+k,lo=now_loc_charge+1)#이분탐색
        if loc == m or charge[loc] > now_loc+k:
            loc-=1
        if loc == now_loc_charge:
            cnt = 0
            break
        else:
            cnt+=1
            now_loc = charge[loc]
            now_loc_charge = loc
    print(f'#{t} {cnt}')