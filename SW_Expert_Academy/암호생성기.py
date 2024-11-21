from collections import deque
T = 10
for tc in range(1, T+1):
    ttc = int(input())
    lst = deque(map(int,input().split()))
    m = 1
    while lst[-1] > 0:
        val = lst.popleft()
        val = max(val - m, 0)
        lst.append(val)
        m = m + 1 if m < 5 else 1
    print(f'#{tc}', *lst)
        