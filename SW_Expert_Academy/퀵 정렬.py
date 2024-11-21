def LMR_sort(A : list, s : int, m : int, e : int):
    #정렬 : 마치 버블 소트처럼
    if A[s] > A[m] : A[s], A[m] = A[m], A[s]
    if A[m] > A[e] : A[m], A[e] = A[e], A[m]
    if A[s] > A[m] : A[s], A[m] = A[m], A[s]
    
def partition(A : list, s : int , e : int) -> int:
    p_val = A[s]
    left, right = s + 1, e
    while (left <= right):
        while left <= right and p_val >= A[left]:
            left += 1
        while left <= right and p_val <= A[right]:
            right -=1
        
        if (left <= right):
            A[left], A[right] = A[right], A[left]
    
    A[s], A[right] = A[right], A[s]
    return right


def quick_sort(A : list, s : int, e : int):
    if (s >= e): return
    m = (s + e) >> 1
    LMR_sort(A, s, m, e)
    if (e - s + 1 > 3):
        # 중간에 pivot값을 가지고, pivot을 가장 왼쪽으로 옮기는 거
        A[m], A[s+1] = A[s+1], A[m] 
        new_piv = partition(A, s+1, e-1)
        quick_sort(A, s, new_piv-1)
        quick_sort(A, new_piv+1, e)
        

T = int(input())
for tc in range(1, T + 1):
    n = int(input())
    lst = list(map(int,input().split())) 
    quick_sort(lst, 0, n-1)
    print(f'#{tc} {lst[n//2]}')