def p(a : int) -> int:
    if parent[a] != a:
        parent[a] = p(parent[a])
    return parent[a]

def union(a: int, b : int):
    a = p(a); b=p(b)
    if (a==b): return False
    parent[max(a,b)] = min(a,b)
    return True

T = int(input())
for t in range(1,T+1):
    n, m = map(int,input().split())
    gh = [ [] for _ in range(n+1)]
    parent = [i for i in range(n+1)]
    for _ in range(m):
        a, b= map(int,input().split())
        union(a,b)
    
    print(f'#{t} {len(set([p(i) for i in parent[1:]]))}')