T = int(input())
for tc in range(1,T+1):
    a, b = input().split()
    cnt = a.count(b)
    print(f'#{tc} {len(a) - (len(b)*cnt) + cnt}')