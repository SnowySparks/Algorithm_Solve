INF = 10 ** 9
ans = INF
def back_track(loc : int, total: int = 0):
    global ans
    if ans <= total:
        return
    if total >= b:
        ans = min(ans, total)
        return
    if total + prefix_sum[n] - prefix_sum[loc-1] < b:
        return
    if (loc == n+1):
        return
    back_track(loc + 1, total + lst[loc])
    back_track(loc + 1, total)
    
    
T = int(input())
for tc in range(1, T+1):
    n, b = map(int ,input().split())
    lst = [0] + list(map(int,input().split()))
    prefix_sum = [0] * (n+1)
    for i in range(1, n+1):
        prefix_sum[i] = prefix_sum[i-1] + lst[i]
    ans = INF
    back_track(1, 0)
    print(f'#{tc} {ans-b}')