T = int(input())

data = {"ZRO" : 0, "ONE" : 1, "TWO" : 2, "THR" : 3, "FOR" : 4, "FIV" : 5, "SIX" :6, "SVN" : 7, "EGT" : 8, "NIN" : 9}

for t in range(1,T+1):
    a, b = input().split()
    b = int(b)
    lst = input().split()
    lst.sort(key = lambda x : data[x])
    print(f'#{t}')
    print(*lst)
        
    