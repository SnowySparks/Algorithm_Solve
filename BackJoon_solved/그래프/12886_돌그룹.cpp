#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,sum;
bool istrue=false, v[1001][1001]; // x, y only
struct io
{
    int a, b;
    io(int a,int b) : a(a), b(b) {}
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int x,y,z; cin >> x >> y >> z;
    sum = x + y + z;
    v[x][y] = true;
    queue<io> q; q.push(io(x,y));
    while(!q.empty()) {
        io loc = q.front(); q.pop();
        if (loc.a == loc.b)
        x = loc.a; y = loc.b; z = sum - x - y;
        if (x!=y) {
            int rx = min(x,y), ry = max(x,y);
            int cx = rx*2, cy= ry-rx;
            if (!v[cx][cy]) {
                v[cx][cy] = true; q.push(io(cx,cy));
            }
        }
        if (z!=y) {
            int ry = min(z,y), rz= max(z,y);
            int cz = rz*2, cy= r-rx;
            if (!v[cx][cy]) {
                v[cx][cy] = true; q.push(io(cx,cy));
            }
        }
    }
}