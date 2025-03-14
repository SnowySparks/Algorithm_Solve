import sys

def input():
    return sys.stdin.readline().rstrip()

n = int(input())
arr = [0] + list(map(int, input().split()))
dp = [0]*(n+1)

for i in range(2, n+1):
    maxVal = arr[i]
    minVal = arr[i]
    for j in range(i-1, -1, -1):
        maxVal = max(maxVal, arr[j+1])
        minVal = min(minVal, arr[j+1])
        dp[i] = max(dp[i], dp[j] + maxVal - minVal)
print(dp[-1])