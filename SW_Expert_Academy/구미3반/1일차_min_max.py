T = int(input())

for test_case in range(1,T+1):
    n = int(input())
    lst = list(map(int,input().split()))
    print(f'#{test_case} {max(lst) - min(lst)}')