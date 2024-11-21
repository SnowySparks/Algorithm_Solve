#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define f(a,b,c) for(int a=b;a<c;a++)
using namespace std;
int n, m;
int map[500][500];
bool v[500][500];
int dr[] {1,-1,0,0};
int dc[] {0,0,1,-1};
int bfs(int sr,int sc) {
    int cnt = 1;
    v[sr][sc] = true;

    queue<pair<int,int> > q;
    q.push({sr,sc});

    while(!q.empty()) {
        pair<int, int> lc = q.front(); q.pop();
        f(i,0,4) {
            int nr = lc.first+dr[i];
            int nc = lc.second +dc[i];

            if (nr >= 0 && nc >= 0 && nr < n && nc < m && v[nr][nc]==false && map[nr][nc]==1) {
                q.push({nr,nc});
                v[nr][nc]=true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int ans = 0;
    int pcnt = 0;
    f(i,0,n) f(k,0,m) cin >> map[i][k];
    f(i,0,n) f(k,0,m) {
        if (!v[i][k] && map[i][k] ==1 ) {
            ans++;
            pcnt = max(pcnt,bfs(i,k));
        }
    }
    cout << ans <<'\n' << pcnt;

    return 0;
}