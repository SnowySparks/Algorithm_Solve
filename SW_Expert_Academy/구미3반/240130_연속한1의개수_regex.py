import re
p = re.compile('[+0]')
T = int(input())
for test in range(1,T+1):
    n = int(input())
    string = input()
    res = re.split(p,string)
    ans = 0
    for result in res:
        ans = max(ans,len(result))
    print(f'#{test} {ans}')