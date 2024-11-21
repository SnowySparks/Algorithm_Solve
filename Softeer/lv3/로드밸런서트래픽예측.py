import sys
from collections import deque
def input():
    return sys.stdin.readline().rstrip()


n, k = map(int,input().split())

gh = [ [] for _ in range(n+1)]
indegree = [0] * (n+1)
outdegree = [0] * (n+1)
dp = [0] * (n+1)


for idx in range(1, n+1):
    lst = list(map(int ,input().split()))
    outdegree[idx] = lst[0]
    for c in range(1, len(lst)):
        gh[idx].append(lst[c])
        indegree[lst[c]]+=1

dp[1] = k
dq = deque([1])

while dq:
    loc = dq.popleft()

    if outdegree[loc] == 0:
        continue

    q = dp[loc] // len(gh[loc])
    remind = dp[loc] % len(gh[loc])

    for idx in range(outdegree[loc]):
        send = q + (1 if idx < remind else 0)
        nxt = gh[loc][idx]
        dp[nxt] += send
        indegree[nxt]-=1

        if not indegree[nxt]:
            dq.append(nxt)
print(*dp[1:])