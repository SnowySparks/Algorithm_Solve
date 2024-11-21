# import sys
# sys.stdin = open('input.txt','r')
#from pprint import pprint as print
T = 10

for t in range(1, T + 1):
    dump = int(input())
    cnt = [0]*101
    lst = list(map(int,input().split()))
    max_val, min_val = max(lst), min(lst)
    for val in lst:
        cnt[val] += 1
        
    while min_val < max_val:
        if cnt[max_val] == 0:
            max_val-=1
            continue
        if cnt[min_val] == 0:
            min_val+=1
            continue
        
        diff = min(cnt[max_val],cnt[min_val],dump)
        cnt[max_val-1]+=diff
        cnt[max_val]-=diff
        cnt[min_val]-=diff
        cnt[min_val+1]+=diff
        dump-=diff
        
        if not cnt[max_val]: max_val-=1
        if not cnt[min_val]: min_val+=1
        if not dump: break
    print(f'#{t} {max_val-min_val}')
    
        