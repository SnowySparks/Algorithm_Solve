# import sys
# sys.stdin = open('input.txt','r')
T = int(input())
def rotate_90clk(lst):
    return [ list(i) for i in zip(*(lst[::-1]))]

# def rotate_90clk_old(lst,n):
#     res = [ [0]*n for _ in range(n) ]
#     for r in range(n):
#         for c in range(n):
#             res[c][n-1-r] = lst[r][c]
#     return res

for t in range(1,T+1):
    n = int(input())
    ans = [ [] for _ in range(n) ]
    lst = [ list(input().split()) for _ in range(n) ]
    for _ in range(3):
        lst = rotate_90clk(lst)
        for i in range(n):
            ans[i].append(''.join(lst[i]))
            
    print(f'#{t}')
    for i in range(n):
        print(' '.join(ans[i]))