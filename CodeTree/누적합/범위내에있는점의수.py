import sys
MAX_LOCATION = 10**6

def input() -> str:
    return sys.stdin.readline().rstrip()


n, q= map(int, input().split())
arr = [0] * (MAX_LOCATION + 1)

for pts in map(int, input().split()):
    arr[pts]+=1

for i in range(1, MAX_LOCATION+1):
    arr[i] += arr[i-1]

for _ in range(q):
    fr, to = map(int ,input().split())
    if (fr == 0):
        print(arr[to])
    else:
        print(arr[to] - arr[fr-1])