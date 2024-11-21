# import sys
# sys.stdin = open('input.txt','r')
T = int(input())
for t in range(1,T+1):
    cnt = [0]*10
    inp = list(map(int,input()))
    for ch in inp: cnt[ch]+=1
    
    #baby
    for i in range(10):
        cnt[i]%=3
    
    #gin
    for i in range(1,9):
        min_val = min(cnt[i-1],cnt[i],cnt[i+1])
        cnt[i-1]-= min_val
        cnt[i]-= min_val
        cnt[i+1]-=min_val
    
    if any(cnt):
        print(f'#{t} false')
    else:
        print(f'#{t} true')