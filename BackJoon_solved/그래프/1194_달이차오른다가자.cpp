#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dr[] {0,0,1,-1};
int dc[] {1,-1,0,0};

int n,m;
string inp[50];
bool v[50][50][64];

int sr = -1,sc = -1;

typedef struct _io {
    int r, c, state, mv;
} io;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) {
        cin >> inp[i]; 
        if (sc == -1) {
        for (int j = 0 ; j < m ; j++) {
            if (inp[i][j] == '0') {
                sr = i ; sc = j;
                inp[i][j] ='.';
            }
        }}
    }
    int ans = -1;
    io st = {sr,sc,0,0};
    queue<io> q; q.push(st); v[sr][sc][0] = true;
    while (!q.empty()) {
        io loc = q.front(); q.pop();
        if (inp[loc.r][loc.c]=='1') {
            ans = loc.mv;
            break;
        }
        for (int i = 0 ; i < 4 ; i++) {
            int nr = loc.r + dr[i], nc = loc.c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                if ((inp[nr][nc] == '.' || inp[nr][nc] == '1')  && !v[nr][nc][loc.state]) {
                    v[nr][nc][loc.state] = true;
                    q.push({nr,nc,loc.state,loc.mv+1});
                }
                else if (inp[nr][nc] >= 'A' && inp[nr][nc] <='F') {
                    int bt = inp[nr][nc] -'A';
                    if ((loc.state&(1<<bt)) && !v[nr][nc][loc.state]) {
                        v[nr][nc][loc.state]=true;
                        q.push({nr,nc,loc.state,loc.mv+1});
                    }
                }
                else if (inp[nr][nc] >= 'a' && inp[nr][nc] <='f') {
                    int bt = inp[nr][nc] -'a';
                    int nxt_state = loc.state | (1<<bt);
                    if (!v[nr][nc][nxt_state]) {
                        v[nr][nc][nxt_state]=true;
                        q.push({nr,nc,nxt_state,loc.mv+1});
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}