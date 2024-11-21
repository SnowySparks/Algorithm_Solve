import sys
MAX_N = 10**6
def input() -> str:
    return sys.stdin.readline().rstrip()

n, q = map(int, input().split())

dp = [ [0] * (n+1) for _ in range(4) ]
# print(len(dp))
for i in range(1, n+1):
    num = int(input())
    dp[num][i] = 1
    for k in range(1, 4):
        dp[k][i] += dp[k][i-1]
    

for _ in range(q):
    fr, to = map(int, input().split())
    print(' '.join([ f'{dp[i][to] - dp[i][fr-1]}' for i in range(1, 4)]))