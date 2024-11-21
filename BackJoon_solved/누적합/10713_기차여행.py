import sys
n, m = map(int,input().split())

order = list(map(int,sys.stdin.readline().rstrip().split()))
cnt = [0] * (n+1)

for k in range(1,m):
    min_v = min(order[k],order[k-1])
    max_v = max(order[k],order[k-1])
    cnt[max_v] = cnt[max_v]-1
    cnt[min_v] = cnt[min_v]+1

for p in range(n): cnt[p+1] +=cnt[p]
ans = 0

for i in range(1,n):
    a,b,c = map(int,sys.stdin.readline().rstrip().split())
    
    if (a - b)*cnt[i] > c :
        ans += c + b*cnt[i]
    else:
        ans+= a*cnt[i]
print(ans)