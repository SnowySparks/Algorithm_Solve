import sys
def input():
    return sys.stdin.readline().rstrip()

n = int(input())
primes = []
cnt = 1
arr = [0] * (n+1)
arr[1] = 1
for i in range(2, n+1):
    if arr[i] == 0:
        primes.append(i)
        cnt+=1
        arr[i] = cnt
    for j in range(len(primes)):
        if primes[j]*i > n: break
        arr[i*primes[j]] = j+2
        if i%primes[j] == 0: break
        
print(cnt)
print(*(arr[1:]))