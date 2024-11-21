temp = [0] * 1000000
cnt = 0
def merge(a : list, s : int, m : int, e : int):
    global cnt
    if a[m] > a[e]:
        cnt += 1
    l_idx, r_idx, idx = s, m + 1, s
    while l_idx <= m and r_idx <= e:
        if a[l_idx] < a[r_idx]:
            temp[idx] = a[l_idx]
            l_idx +=1
        else:
            temp[idx] = a[r_idx]
            r_idx +=1
        idx += 1
    
    while l_idx <= m:
        temp[idx] = a[l_idx]
        l_idx +=1
        idx += 1
    while r_idx <= e:
        temp[idx] = a[r_idx]
        r_idx +=1
        idx += 1
    for idx in range(s, e+1):
        a[idx] = temp[idx]

def merge_sort(a : list, s : int = 0, e :int = None):
    if (e == None): e = len(a)-1
    if (s == e): return
    d = (e - s + 1) >> 1
    merge_sort(a, s, s + d -1)
    merge_sort(a, s + d, e)
    merge(a, s, s + d -1, e)

T = int(input())
for tc in range(1, T+1):
    cnt = 0
    n = int(input())
    lst = list(map(int, input().split()))
    merge_sort(lst)
    # print(lst)
    print(f'#{tc} {lst[n>>1]} {cnt}')