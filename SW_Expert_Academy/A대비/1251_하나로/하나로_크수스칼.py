from math import floor, sqrt
def dist(a : tuple , b :  tuple) ->float:
    return (X[a] - X[b])**2 + (Y[a] - Y[b])**2

def parent(x : int):
    if x != p[x]:
        p[x] = parent(p[x])
    return p[x]

def merge(node1 : int, node2 : int):
    node1 = parent(node1)
    node2 = parent(node2)
    
    if (node1 == node2): return False
    
    p[max(node1, node2)] = min(node1, node2)
    return True

T = int(input())
for tc in range(1, T+1):
    n = int(input())
    p = list(range(n))
    X = list(map(int, input().split()))
    Y = list(map(int, input().split()))
    E = float(input())
    
    edge = []
    for i in range(n-1):
        for k in range(i+1, n):
            cost = E * dist(i, k)
            edge.append((cost, i, k))
    
    edge.sort()
    edge_cnt = 0
    ans = 0
    for cost, n1, n2 in edge:
        if merge(n1, n2):
            ans += cost
            edge_cnt += 1
        if edge_cnt == n-1:
            break
    print(f'#{tc} {floor(ans + 0.5)}')