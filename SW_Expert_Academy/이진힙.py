# import heapq
# import sys
# sys.stdin = open('input.txt','r')


def heappush(x):
    global last_idx
    last_idx+=1
    heap[last_idx] = x
    p = last_idx//2
    child = last_idx
    while p and heap[p] > heap[child]:
        heap[p], heap[child] = heap[child], heap[p]
        child = p
        p = child//2
    
T = int(input())
for tc in range(1, T+1):
    n = int(input())
    last_idx = 0
    lst = list(map(int,input().split()))
    heap = [0] * (n + 1)
    for val in lst:
        heappush(val)
    ans = 0
    ancester = n//2
    while ancester:
        ans += heap[ancester]
        ancester//=2
    print(f'#{tc} {ans}')
        