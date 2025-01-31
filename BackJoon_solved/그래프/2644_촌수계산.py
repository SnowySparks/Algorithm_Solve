import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

n = int(input())
a, b = map(int, input().split())
edgeCnt = int(input())

adj = [ [] for _ in range(n+1)]
v = [-1] * (n+1)
for _ in range(edgeCnt):
    p, c = map(int,input().split())
    adj[p].append(c)
    adj[c].append(p)

v[a] = 0
dq = deque()
dq.appendleft(a)

while dq:
    loc = dq.popleft()
    for child in adj[loc]:
        if v[child] == -1:
            v[child] = v[loc] + 1
            dq.append(child)

print(v[b])