from collections import deque
T = 10
for tc in range(1,T+10):
    n, inp = input().split()
    dq = deque()
    for ch in inp:
        dq.append(ch)
        while len(dq) >= 2 and dq[-1] == dq[-2]:
            dq.pop()
            dq.pop()
    ans = ''.join(dq)
    print(f'#{tc} {ans}')
    