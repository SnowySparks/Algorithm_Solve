import sys
from collections import deque

class pts:
    def __init__(self, _x  : int = 0 , _y : int = 0) -> None:
        self.x = _x
        self.y = _x
        self.rx = 0
        self.ry = 0
    def cal_relative(self, ptx : int, pty : int):
        rx = self.x - ptx
        ry = self.y - pty
        
    def __lt__(self, other : 'pts') ->bool:
        if self.ry*other.rx != self.rx*other.ry : return self.ry*other.rx < self.rx*other.ry
        if self.y != other.y : return self.y < other.y
        return self.x < other.x
    def __eq__(self, __value: 'pts') -> bool:
        if self.x == __value.x and self.y == __value.y  and self.rx == __value.rx and self.ry==__value.ry: return True
        else: return False
    
    def out(self):
        print(self.x ,self.y, self.rx. self.ry)

def ccw(a:pts, b:pts, c:pts) -> int :
    return (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y)
    
n = int(input())
lst = [pts() for _ in range(n)]

for i in range(n):
    lst[i].x, lst[i].y = map(int,sys.stdin.readline().rstrip().split())
    if i > 0 and lst[i] < lst[0]: 
        lst[i], lst[0] = lst[0] , lst[i]
for i in range(1,n):
    lst[i].cal_relative(lst[0].x,lst[0].y)
    
lst2 = [lst[0]] + list(sorted(lst[1:]))

dq = deque(); dq.append(0); dq.append(1)
for i in range(2,n):
    while len(dq) >=2:
        sec = dq.pop(); fir = dq[-1]
        if ccw(lst2[fir],lst2[sec],lst2[i]) > 0 :
            dq.append(sec)
            break
    dq.append(i)

print(len(dq)+1)
