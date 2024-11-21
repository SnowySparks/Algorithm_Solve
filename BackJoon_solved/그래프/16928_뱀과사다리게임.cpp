#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define f(a,b,c) for(int a=b;a<c;a++)
int n, m;
int nxt[101];
int d[101];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    f(i,0,101) {d[i] = -1; nxt[i]=i;}
    f(i,0,n+m) {
        int a, b; cin >> a >> b;
        nxt[a] = b;
    }
    queue<int> q; q.push(1); d[1] = 0;
    while(!q.empty()) {
        int loc = q.front(); q.pop();
        if (loc == 100) break;
        f(i,1,7) {
            int nl = loc + i;
            if (nl <= 100) {
                if (nxt[nl] != nl && d[nxt[nl]] == -1) {
                    d[nxt[nl]] = d[loc] + 1;
                    q.push(nxt[nl]);
                }
                else if (nxt[nl] == nl && d[nl] == -1) {
                    d[nl] = d[loc] + 1;
                    q.push(nl);
                }
            }
        }
    }
    cout << d[100];
    return 0;
}