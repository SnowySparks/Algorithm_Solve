from collections import Counter
T = int(input())
for test in range(1,T+1):
    n = int(input())
    inp = input()
    cnt = Counter(inp).most_common()
    cnt.sort(key = lambda x : (-x[1],-ord(x[0])))
    print(f'#{test} {cnt[0][0]} {cnt[0][1]}')