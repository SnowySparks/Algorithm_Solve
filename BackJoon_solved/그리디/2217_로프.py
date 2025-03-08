import sys
def input():
    return sys.stdin.readline().rstrip()

n = int(input())
lst = [0]*n
for i in range(n):
    lst[i] = int(input())    
lst.sort()

ans = 0
for idx in range(n):
    ans = max(ans, (n-idx) * lst[idx])
print(ans)
