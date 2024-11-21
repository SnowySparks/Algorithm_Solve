T = int(input())
for tc in range(1, T+1):
    N, M = map(int,input().split())
    lst = list(map(int,input().split()))
    print(f'#{tc} {lst[M%N]}')