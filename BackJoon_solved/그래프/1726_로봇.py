import sys
from collections import deque

EAST = 0
SOUTH = 1
WEST = 2
NORTH = 3
INF = 10**9

#입력에선 동 1, 서 2, 남 3, 북 4로 변경되는 것을 변형하기 위함
changeDirVar = {
    1: EAST,
    2: WEST,
    3: SOUTH,
    4: NORTH
}

mv = [
    (0, 1),
    (1, 0),
    (0, -1),
    (-1, 0)
]
    


def turnRight(dir : int) -> int:
    return (dir + 1)%4

def turnLeft(dir : int) -> int:
    return (dir + 3)%4

def input() -> str:
    return sys.stdin.readline().rstrip()

n, m = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(n)]

vis = [ [ [INF] * 4 for _ in range(m) ] for _ in range(n) ]

start_r, start_c, start_dir = map(int, input().split())
start_r, start_c = start_r - 1, start_c -1
start_dir = changeDirVar.get(start_dir)
end_r, end_c, end_dir = map(int, input().split())
end_r, end_c = end_r - 1, end_c -1
end_dir = changeDirVar.get(end_dir)


vis[start_r][start_c][start_dir] = 0
dq = deque()
dq.append((start_r, start_c, start_dir))


while dq:
    r, c, dir = dq.popleft()
    
    # 직진
    for moveDir in range(1, 4):
        
        nr, nc = r + mv[dir][0] * moveDir, c + mv[dir][1] * moveDir
        if 0 <= nr < n and 0 <= nc < m:
            if arr[nr][nc] == 1: break
            if vis[nr][nc][dir] != INF: continue
            vis[nr][nc][dir] = vis[r][c][dir] + 1
            dq.append((nr, nc, dir))
        
    # 좌우
    leftDir = turnLeft(dir)
    if vis[r][c][leftDir] == INF:
        vis[r][c][leftDir] = vis[r][c][dir] + 1
        dq.append((r, c, leftDir))
    
    rightDir = turnRight(dir)
    if vis[r][c][rightDir] == INF:
        vis[r][c][rightDir] = vis[r][c][dir] + 1
        dq.append((r, c, rightDir))
    

print(vis[end_r][end_c][end_dir])
