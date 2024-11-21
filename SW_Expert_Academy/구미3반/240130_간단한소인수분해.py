T = int(input())
primes = [2, 3, 5, 7, 11]
for test in range(1,T+1):
    ans = []
    n = int(input())
    for prime in primes:
        cnt = 0
        while (not n % prime):
            n//=prime
            cnt+=1
        ans.append(cnt)
    print(f'#{test}',*ans)
    