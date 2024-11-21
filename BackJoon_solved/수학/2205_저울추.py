n = int(input())
limit = 1
ans = []
v = [False] * (n+1)

while limit <= n :
    limit = limit *2
    

for i in range(n,0,-1):
    k = limit
    while k >= 1:
        if k - i <= n and not v[k-i]:
            ans.append(k-i)
            v[k-i]=True
            break
        k=k//2
     
for k in range(len(ans)-1,-1,-1):
    print(ans[k]) 