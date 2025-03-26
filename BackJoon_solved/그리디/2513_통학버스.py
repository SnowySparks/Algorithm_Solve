import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

n, k, s = map(int ,input().split())
arr = []

leftSide = deque()
rightSide = deque()

for _ in range(n):
    arr.append(list(map(int, input().split())))

arr.sort(key= lambda x : x[0])
    
for loc, p in arr:
    if loc <= s:
        leftSide.append([s-loc, p])
    else:
        rightSide.appendleft([loc-s, p])

def func(dq : deque) -> int:
    res = 0
    leftBus = k # 남아있는 자리
    while dq:
        maxDist, lastP = dq.popleft()
        cnt = lastP // k
        res += maxDist*2*cnt
        lastP %= k
        
        if lastP > 0:
            res += maxDist*2
            leftBus = k - lastP
            while dq and dq[0][1] <= leftBus:
                leftBus -= dq[0][1]
                dq.popleft()
                
    return res

print(f"{func(leftSide) + func(rightSide)}")